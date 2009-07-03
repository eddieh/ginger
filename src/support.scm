; Major bitrot lies ahead.  This file will be dumped as soon as gin2 is 
; self hosting

(define-macro (assert expr . others)
  (define (make-print-list prefix lst)
    (cond
     ((null? lst) '())
     ((symbol? (car lst))
      (cons #\newline
	(cons (list 'quote (car lst))
	  (cons ": " (cons (car lst) (make-print-list #\newline (cdr lst)))))))
     (else 
      (cons prefix (cons (car lst) (make-print-list "" (cdr lst)))))))
  (define (vars-of expr)
    (let loop ((expr expr) (vars '()))
      (cond
       ((not (pair? expr)) vars)	; not an application -- ignore
       ((memq (car expr) 
	      '(quote let let* letrec let*-values lambda cond quasiquote
		      case define do assert))
	vars)				; won't go there
       (else				; ignore the head of the application
	(let inner ((expr (cdr expr)) (vars vars))
	  (cond 
	   ((null? expr) vars)
	   ((symbol? (car expr))
	    (inner (cdr expr)
		   (if (memq (car expr) vars) vars (cons (car expr) vars))))
	   (else
	    (inner (cdr expr) (loop (car expr) vars)))))))))

  (cond
   ((null? others)		; the most common case
    `(or ,expr (begin (cerr "failed assertion: " ',expr nl "bindings"
			    ,@(make-print-list #\newline (vars-of expr)) nl)
		      (error "assertion failure"))))
   ((eq? (car others) 'report:) ; another common case
    `(or ,expr (begin (cerr "failed assertion: " ',expr
			    ,@(make-print-list #\newline (cdr others)) nl)
		      (error "assertion failure"))))
   ((not (memq 'report: others))
    `(or (and ,expr ,@others)
	 (begin (cerr "failed assertion: " '(,expr ,@others) nl "bindings"
		      ,@(make-print-list #\newline
			 (vars-of (cons 'and (cons expr others)))) nl)
		      (error "assertion failure"))))
   (else			; report: occurs somewhere in 'others'
    (let loop ((exprs (list expr)) (reported others))
      (cond
       ((eq? (car reported) 'report:)
	`(or (and ,@(reverse exprs))
	     (begin (cerr "failed assertion: " ',(reverse exprs)
			  ,@(make-print-list #\newline (cdr reported)) nl)
		    (error "assertion failure"))))
       (else (loop (cons (car reported) exprs) (cdr reported)))))))
)
    
(define-macro (assure exp error-msg) `(assert ,exp report: ,error-msg))

(define (cout . args)
  (for-each (lambda (x)
              (if (procedure? x) (x) (display x)))
            args))

(define (cerr . args)
  (for-each (lambda (x)
              (if (procedure? x) (x) (display x)))
            args))

(define nl (string #\newline))

(define-macro (read-line . x) `(read-text-line . ,x))

(define-macro (inc! x) `(set! ,x (+ 1 ,x)))
(define-macro (++! x) `(set! ,x (+ 1 ,x)))

(define-macro (inc x) `(+ 1 ,x))
(define-macro (++ x) `(+ 1 ,x))

(define-macro (dec! x) `(set! ,x (- ,x 1)))
(define-macro (--! x) `(set! ,x (- ,x 1)))

(define-macro (dec x) `(- ,x 1))
(define-macro (-- x) `(- ,x 1))


(define-macro (when condition . stmts)
  `(and ,condition (begin ,@stmts)))
(define-macro (whennot condition . stmts)
  `(or ,condition (begin ,@stmts)))
(define-macro (begin0 form . forms)
  (let ((var (gensym)))
    `(let ((,var ,form)) ,@forms ,var)))
(define-macro (push! item ls)
  `(set! ,ls (cons ,item ,ls)))
(define-macro (string-null? str) `(zero? (string-length ,str)))
(define (cons* first . rest)
  (let recur ((x first) (rest rest))
    (if (pair? rest)
	(cons x (recur (car rest) (cdr rest)))
	x)))
(define values list)

(define (call-with-values producer consumer)
  (apply consumer (producer)))

; Like let* but allowing for multiple-value bindings: SRFI-11
(define-macro (let*-values bindings . body)
  (if (null? bindings) (cons 'let (cons '() body))
      (let
	  ((vars (caar bindings))
	   (binding-rest (cdar bindings))
	   (cont 
	    (cons 'let*-values 
		  (cons (cdr bindings) body))))
	(cond				; single var, treat like let*
	 ((and (pair? vars) (null? (cdr vars))) 
	  `(let ((,(car vars) . ,binding-rest)) ,cont))
	 ((and (pair? vars) (pair? (cdr vars)) (null? (cddr vars)))
	  (let ((val (gensym)))		; two proper variables
	    `(let* ((,val . ,binding-rest)
		    (,(car vars) (car ,val))
		    (,(cadr vars) (cadr ,val))) ,cont)))
	 (else			; the most generic case
	  `(apply (lambda ,vars ,cont) . ,binding-rest))))))

(define-macro (lookup-def key alist . others)
  (let ((nkey (gensym))
	(nalist (gensym))
	(res (gensym))
	)
    `(let ((,nkey ,key) (,nalist ,alist))
       (let ((,res (assq ,nkey ,nalist)))
	 (if ,res
	   (let ((,res (cdr ,res)))
	     (cond
	       ((not (pair? ,res)) ,res)
	       ((null? (cdr ,res)) (car ,res))
	       (else ,res)))
	   ,(cond
	      ((null? others)
		`(error "Failed to find " ,nkey " in " ,nalist))
	      ((eq? (car others) 'warn:)
		`(begin
		   (cerr "Failed to find " ,nkey " in " ,nalist #\newline)
		   ,(cadr others)))
	      (else (car others))))))))

(define-macro (env.find key) `(%%env.find ',key))
(define-macro (env.demand key) `(%%env.demand ',key))
(define-macro (env.bind key value) `(%%env.bind ',key ,value))

(define-macro (cond-expand . clauses)
  (define feature-ids '(gambit srfi-0 srfi-2 srfi-12))
  (define (feature-req-satisfies? fr) ; does feature-request satisfies?
    (cond
     ((memq fr feature-ids) #t)
     ((not (pair? fr)) #f)
     ((eq? 'and (car fr))
      (let loop ((clauses (cdr fr)))
	(or (null? clauses)
	    (and (feature-req-satisfies? (car clauses))
		 (loop (cdr clauses))))))
     ((eq? 'or (car fr))
      (let loop ((clauses (cdr fr)))
	(and (pair? clauses)
	     (or (feature-req-satisfies? (car clauses))
		 (loop (cdr clauses))))))
     ((eq? 'not (car fr))
      (not (feature-req-satisfies? (and (pair? (cdr fr)) (cadr fr)))))
     (else #f)))
  (let loop ((clauses clauses))
    (if (null? clauses) '(error "Unfulfilled cond-expand")
	(let* ((feature-req (if (pair? (car clauses)) (caar clauses)
				(error "<cond-expand clause> is not a list")))
	       (cmd-or-defs* (cons 'begin (cdar clauses))))
	  (cond
	   ((and (eq? 'else feature-req) (null? (cdr clauses)))
	    cmd-or-defs*)
	   ((feature-req-satisfies? feature-req)
	    cmd-or-defs*)
	   (else (loop (cdr clauses))))))))

(define-macro (define-opt bindings body . body-rest)
  (let loop ((curr bindings) (reqd '()))
    (cond
      ((not (pair? curr))			; No optional bindings,
	`(define ,bindings ,body ,@body-rest))  ; regular define
      ((and (pair? (car curr)) (eq? 'optional (caar curr)))
	`(define ,(append (reverse (cons #!optional reqd))
		    (cdar curr) (cdr curr))
	   ,body ,@body-rest))
      (else (loop (cdr curr) (cons (car curr) reqd))))))

(define-macro (handle-exceptions var handle-expr body . bodies)
  (let ((k (gensym)))
    `((dynamic-let '()
       (lambda ()
        (call-with-current-continuation
	 (lambda (,k)
	   (with-exception-handler
	    (lambda (,var)		      ; The handler will be executed
	      (,k (lambda () ,handle-expr)))  ; after ##dynamic-let above exits
	    (lambda ()
	      (let ((result (begin ,body ,@bodies))) ; multiple-values are
		(lambda () result)))))))))))	     ; first class in Gambit

(define-macro (and-let* claws . body)
  (if (null? body)
      (cond 
       ((null? claws) #t)		; (and-let* () )
       ((not (pair? claws)) `(error "claws must be a list" ',claws))
       ; re-write (and-let* ((claw ... last-claw)) ) into
       ; (and-let* ((claw ...)) body) with 'body' derived from the last-claw
       (else
	(let* ((claws-rev (reverse claws))
	       (last-claw (car claws-rev))
	       (first-claws (reverse (cdr claws-rev)))
	       (new-body
		(if (pair? last-claw)
		    (if (null? (cdr last-claw))	; (and-let* (... (exp)) )
			(car last-claw)
			(cadr last-claw))	; (and-let* (... (var exp)) )
		    last-claw			; (and-let* (... var) )
		    )))
	  (list 'and-let* first-claws new-body))))
  ; generic case, 'body' is present
  (let loop ((claws claws))
    (cond
     ((null? claws)			; (and-let* () form ...)
      (cons 'begin body))
     ((not (pair? claws))
      `(error "claws must be a list" ',claws))
     ((not (pair? (car claws)))		; (and-let* ( var claw ...) body ...)
      (if (symbol? (car claws))
	  (list 'and (car claws) (loop (cdr claws)))
	  `(error "wrong claw:" ',(car claws))))
     ((null? (cdar claws))		; (and-let* ( (exp) claw... ) body ...)
      (list 'and (caar claws) (loop (cdr claws))))
     (else				; (and-let* ((var exp) claw...)body...)
      (list 'let (list (car claws))
	    (list 'and (caar claws) (loop (cdr claws)))))))
))

(define-macro (define-method . args)

  (define (err) (error "Ill-formed `define-method'") #f)

  (define (def-method classes name parms body)
    `(DEFINE ,name
       (MAKE-METHOD ',name
                      (LAMBDA ,parms ,@body)
                      ,@(map (lambda (x) `(LAMBDA () ,x)) classes))))

  (let loop ((args args) (classes '()))
    (if (pair? args)
      (let ((rest (cdr args)) (arg (car args)))
        (cond ((symbol? arg)
               (loop rest (cons arg classes)))
              ((pair? arg)
               (let ((name (car arg)) (parms (cdr arg)))
                 (if (and (pair? classes) (symbol? name) (pair? rest))
                   (def-method classes name parms rest)
                   (err))))
              (else
               (err))))
      (err))))

(define (make-method name proc . classes)
  (let ((method-descr (assq name method-descriptors)))

    (if (not method-descr) ; first definition?

      ; create new method descriptor...

      (let ((method-descr
              (cons name (cons #f (map (lambda (x) (cons x proc)) classes)))))

        (define (generic-proc self . rest)
          (let loop ((l (cddr method-descr)))
            (if (pair? l)
              (let ((entry (car l)))
                (if (((car entry)) self)
                  (apply (cdr entry) self rest)
                  (loop (cdr l))))
              (error "Method is not defined for this object:"
                     (car method-descr) self))))

        (set-car! (cdr method-descr) generic-proc)

        (set! method-descriptors (cons method-descr method-descriptors))

        generic-proc)

      ; update method descriptor if it existed before...

      (let ()

        (define (add-entry class)
          (let ((new-entry (cons class proc)))
            (let loop ((l (cddr method-descr)))
              (let ((entry (car l)) (rest (cdr l)))
                (cond ((eq? (class) ((car entry))) ; replace entry
                       (set-car! l new-entry))
                      ((pair? rest)
                       (loop rest))
                      (else ; add at head of dispatch table
                       (set-cdr! (cdr method-descr)
                         (cons new-entry (cddr method-descr)))))))))

        (for-each add-entry classes)

        (cadr method-descr)))))

(define method-descriptors '())

(define-macro (define-struct name . fields)
  (define (err) (error "Ill-formed `define-struct'") #f)
  (define (sym . strings) (string->symbol (apply string-append strings)))
  (if (symbol? name)
    (let ((name-str (symbol->string name)))
      (let loop ((l1 fields) (l2 '()) (i 1))
        (if (pair? l1)
          (let ((rest (cdr l1)) (field (car l1)))
            (if (symbol? field)
              (let* ((field-str (symbol->string field))
                     (field-ref (sym name-str ":get-" field-str))
                     (field-set! (sym name-str ":set-" field-str)))
                (loop rest
                      (cons `(define (,field-set! X Y) (vector-set! X ,i Y))
                            (cons `(define (,field-ref X) (vector-ref X ,i))
                                  l2))
                      (+ i 1)))
              (err)))
          `(begin
             ,@l2
             (define ,(sym name-str "-tag") (list ',name))
             (define (,(sym name-str ":new") ,@fields)
               (vector ,(sym name-str "-tag") ,@fields))
             (define (,(sym name-str "?") X)
               (and (vector? X) (= (vector-length X) ,i)
                    (eq? (vector-ref X 0) ,(sym name-str "-tag"))))))))
    (err)))

(define-macro (ginger-for-each i v body)
  `(letrec ( (,i #f) (loop
       (lambda (z)
	 (if (not (null? z))
	       (begin
		 (set! ,i (car z))
		 ,body
		 (loop (cdr z)))))) )
       (loop ,v)))

(define (print . args)
  (if (output-port? (car args))
      (ginger-for-each a (cdr args) (display a (car args)))
      (ginger-for-each a args (display a))))

(define (println . args)
  (if (output-port? (car args))
      (begin
	(ginger-for-each a (cdr args) (display a (car args)))
	(display "\n" (car args)))
      (begin
	(ginger-for-each a args (display a))
	(display "\n"))))

; Taken from srfi sample implementation
(define (last lis) (car (last-pair lis)))

(define (ginger-head v)
  (reverse (cdr (reverse v))))

(define (last-pair lis)
;  (check-arg pair? lis last-pair)
  (let lp ((lis lis))
    (let ((tail (cdr lis)))
      (if (pair? tail) (lp tail) lis))))

; a common mapping..
(define-macro (while test . body)
  `(let loop ()
     (cond
       (,test
	,@body
         (loop)))))

; Split a string on a given character
(define (string-split str ch)
(begin
    (assure (char? ch) "Argument 'ch' must be a valid character.")
;    (println str)
    (assure (string? str) "Argument 'str' must be a valid string.")
  (let ((len (string-length str)))
    (letrec
	((split
	  (lambda (a b)
	    (cond
	     ((>= b len) (if (= a b) '("") (cons (substring str a b) '())))
	     ((char=? ch (string-ref str b)) (if (= a b)
						 (cons "" (split (+ 1 a) (+ 1 b)))
						 (cons (substring str a b) (split (+ 1 b) (+ 1 b)))))
	     (else (split a (+ 1 b)))))))
      (split 0 0)))) )

(define (string-join lst ch)
  (if (<= (length lst) 1) (car lst)
      (string-append (car lst) ch (string-join (cdr lst)))))

(define (table-key? t k)
  (if (eq? (table-ref t k) '__reserved-unbound-table-key) #f #t))

(define (env-get env command)
  (let ((loc (table-ref env command 'did-not-find-it)))
    (if (eq? loc 'did-not-find-it)
      (let ((loc (table-ref env 'parent-environment 'did-not-find-it)))
        (if (eq? loc 'did-not-find-it)
	      (begin ; giveup
		(println "Could not find term: " command)
		(exit))
	      (env-get loc command)))
	loc)))

(define (env-set env command value)
  (let ((loc (table-ref env command 'did-not-find-it)))
    (if (eq? loc 'did-not-find-it)
	(let ((loc (table-ref env 'parent-environment 'did-not-find-it)))
	  (if (eq? loc 'did-not-find-it)
	      (begin ; giveup
		(println "Could not find term: " command)
		(exit))
	      (env-set loc command value)))
	(table-set! env command value))))

(define (env-exec environment . args)
  (let ((command (car args))
	(arguments (cdr args)) )
    (begin
      (let ((actual-command (env-get environment command)))
        (if (procedure? actual-command)
	  (if (null? arguments)
	    (begin
;	      (println "Executing command with no args")
	      (actual-command))
	    (begin
;	      (println "Executing command with arguments")
	      (apply actual-command arguments)))
	  (begin
;	    (println "Not a procedure")
	    (if (null? arguments)
	      actual-command
	      (begin
	        ; TODO: Infix evaluation.
	        ; (println "Infix? This part not finished.")
                (env-exec environment (cadr args) (car args) (caddr args))
		
		
		
              ))))))))

(define (make-env input)
  (let ((my-table (make-table)))
    (ginger-for-each i input
      (begin
        (table-set! my-table (car i) (cadr i))))
    my-table))
        
(define (ginger-or a b)
  (or a b))

(define (ginger-and a . b)
  (if (eq? (length b) 1) (and a (car b))
      (and a (car b) (cadr b))))
