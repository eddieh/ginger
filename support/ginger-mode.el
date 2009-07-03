; Ginger mode
;
; This is what I add to my .emacs file to make it work (put it in the site-lisp
; directory referenced on the next line):
;
; (add-to-list 'load-path "~/.emacs.d/site-lisp")
; (autoload 'ginger-mode "ginger-mode" "Ginger editing mode." t)
; (add-to-list 'auto-mode-alist '("\\.gin\\'" . ginger-mode))

(provide 'ginger)

(defvar ginger-mode-syntax-table nil "")
(defvar ginger-mode-abbrev-table nil "")
(defvar ginger-max-indent 7 "")
(defvar ginger-standard-indent 2 "")

(defconst ginger-font-lock-keywords
  (list
   ; Define constants
   '(";.*" . font-lock-comment-face)
   '("\\(\"[^\"]+\"\\)" . font-lock-string-face)
   '("\\<ascii-\\sw*\\>" . font-lock-constant-face)
   '("\\<true\\>" . font-lock-constant-face)
   '("\\<false\\>" . font-lock-constant-face)
   '("(" . font-lock-builtin-face)
   '(")" . font-lock-builtin-face)
   '("\\<\\sw*\\>:" . font-lock-keyword-face)
   '("\\<define\\>" . font-lock-keyword-face)
   '("\\<require\\>" . font-lock-keyword-face)
   '("\\<ensure\\>" . font-lock-keyword-face)
   '("\\<if\\>" . font-lock-keyword-face)
   '("\\<while\\>" . font-lock-keyword-face)
   '("\\<print\\>" . font-lock-keyword-face)
   '("\\<println\\>" . font-lock-keyword-face)
   '("\\<set\\>" . font-lock-keyword-face)
   '("\\<get\\>" . font-lock-keyword-face)
   '("<\\<\\sw*\\>>" . font-lock-type-face)
   "Highlighting expressions for Ginger mode"))

(if (not ginger-mode-syntax-table)
    (let ((i 0))
      (setq ginger-mode-syntax-table (make-syntax-table))
      (set-syntax-table ginger-mode-syntax-table)
      (while (< i ?0)
	(modify-syntax-entry i "_   ")
	(setq i (1+ i)))
      (setq i (1+ ?9))
      (while (< i ?A)
	(modify-syntax-entry i "_   ")
	(setq i (1+ i)))
      (setq i (1+ ?Z))
      (while (< i ?a)
	(modify-syntax-entry i "_   ")
	(setq i (1+ i)))
      (setq i (1+ ?z))
      (while (< i 128)
	(modify-syntax-entry i "_   ")
	(setq i (1+ i)))
      (modify-syntax-entry ?  "    ")
      (modify-syntax-entry ?- "_   ")
      (modify-syntax-entry ?\t "    ")
      (modify-syntax-entry ?\n ">   ")
      (modify-syntax-entry ?\f ">   ")
      (modify-syntax-entry ?\; "<   ")
      (modify-syntax-entry ?` "'   ")
      (modify-syntax-entry ?' "'   ")
      (modify-syntax-entry ?, "'   ")
      (modify-syntax-entry ?. "_   ")
      (modify-syntax-entry ?# "'   ")
      (modify-syntax-entry ?\" "\"    ")
      (modify-syntax-entry ?\\ "\\   ")
      (modify-syntax-entry ?\[ "(]  ")
      (modify-syntax-entry ?\] ")[  ")
      (modify-syntax-entry ?\( "()  ")
      (modify-syntax-entry ?\) ")(  ")))

(define-abbrev-table 'ginger-mode-abbrev-table ())

(defun ginger-mode-variables ()
  (set-syntax-table ginger-mode-syntax-table)
  (setq local-abbrev-table ginger-mode-abbrev-table)
  (make-local-variable 'indent-line-function)
  (setq indent-line-function 'ginger-indent-line)
  (make-local-variable 'comment-start)
  (setq comment-start ";")
  (make-local-variable 'comment-start-skip)
  (setq comment-start-skip ";+ *")
  (make-local-variable 'font-lock-defaults) 
  (setq font-lock-defaults '(ginger-font-lock-keywords ginger-font-lock-keywords ginger-font-lock-keywords))
  (setq indent-tabs-mode nil) 
)

(defun ginger-mode-commands (map)
  (define-key map "\t" 'ginger-indent-line)
  (define-key map "\C-c<" 'ginger-shift-left)
  (define-key map "\C-c>" 'ginger-shift-right)
)

(defvar ginger-mode-map (make-sparse-keymap))
(ginger-mode-commands ginger-mode-map)

(defun ginger-mode ()
  "Major mode for editing Ginger code.
Commands:
\\{ginger-mode-map}

Semicolons start comments. Entry to this mode calls the value of ginger-mode-hook if that value is non-nil."
  (interactive)
  (kill-all-local-variables)
  (make-local-variable 'fix-mismatch)
  (setq fix-mismatch t)
  (use-local-map ginger-mode-map)
  (setq major-mode 'ginger-mode)
  (setq mode-name "Ginger")
  (ginger-mode-variables)
  (run-hooks 'ginger-mode-hook))

(defun ginger-indent-line ()
  "Indent current line of Sample code."
  (interactive)
  (let ((savep (> (current-column) (current-indentation)))
	(current-indent (current-indentation))
	(last-indent 
	 (if (bobp)
	     0
	   (save-excursion
	     (forward-line -1)
	     (current-indentation))))
	(max-indent 0)
	(amt 2))
    (progn
      (setq max-indent (+ last-indent 2))
      (if (< current-indent last-indent)
	  (setq amt last-indent)
	(if (> current-indent max-indent)
	    (setq amt max-indent)
	  (setq amt last-indent)))
      (if savep
	  (save-excursion (indent-line-to amt))
	(indent-line-to amt)))))

(defun ginger-shift-left (start end &optional count)
  ""
  (interactive (if mark-active
		   (list (region-beginning) (region-end) current-prefix-arg)
		 (list (point) (point) current-prefix-arg)))
  (if count
      (setq count (prefix-numeric-value count))
    (setq count 2))
  (when (> count 0)
    (save-excursion
      (goto-char start)
      (while (< (point) end)
	(if (and (< (current-indentation) count)
		 (not (looking-at "[ \t]*$")))
	    (error "Can't shift all lines enough"))
	(forward-line))
      (indent-rigidly start end (- count))))
  (setq deactivate-mark nil))

(defun ginger-shift-right (start end &optional count)
  ""
  (interactive (if mark-active
		   (list (region-beginning) (region-end) current-prefix-arg)
		 (list (point) (point) current-prefix-arg)))
  (if count
      (setq count (prefix-numeric-value count))
    (setq count 2))
  (indent-rigidly start end count)
  (setq deactivate-mark nil))
