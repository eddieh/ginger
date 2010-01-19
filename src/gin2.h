#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PROG 1
#include "ginger.h"
#include <math.h>
#include <ctype.h>
#include <pango/pangocairo.h>
#include "pango-support.h"
#include <cairo/cairo.h>
#include <cairo/cairo-pdf.h>
typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ loc4;
GIN_OBJ loc5;
GIN_OBJ loc6;
GIN_OBJ loc7;
GIN_OBJ loc8;
GIN_OBJ loc9;
GIN_OBJ loc10;
GIN_OBJ loc11;
GIN_OBJ loc12;
GIN_OBJ loc13;
GIN_OBJ loc14;
GIN_OBJ loc15;
GIN_OBJ loc16;
GIN_OBJ loc17;
GIN_OBJ loc18;
GIN_OBJ loc19;
GIN_OBJ loc20;
GIN_OBJ loc21;
GIN_OBJ loc22;
GIN_OBJ loc23;
GIN_OBJ loc24;
GIN_OBJ loc25;
GIN_OBJ loc26;
GIN_OBJ loc27;
GIN_OBJ loc28;
GIN_OBJ loc29;
GIN_OBJ loc30;
GIN_OBJ loc31;
GIN_OBJ loc32;
GIN_OBJ loc33;
GIN_OBJ loc34;
GIN_OBJ loc35;
GIN_OBJ loc36;
GIN_OBJ loc37;
GIN_OBJ loc38;
GIN_OBJ loc39;
GIN_OBJ loc40;
GIN_OBJ loc41;
GIN_OBJ loc42;
GIN_OBJ loc43;
GIN_OBJ loc44;
GIN_OBJ loc45;
GIN_OBJ loc46;
GIN_OBJ loc47;
GIN_OBJ loc48;
GIN_OBJ loc49;
GIN_OBJ loc50;
GIN_OBJ loc51;
GIN_OBJ loc52;
GIN_OBJ loc53;
GIN_OBJ loc54;
GIN_OBJ loc55;
GIN_OBJ loc56;
GIN_OBJ loc57;
GIN_OBJ loc58;
GIN_OBJ loc59;
GIN_OBJ loc60;
GIN_OBJ loc61;
GIN_OBJ loc62;
GIN_OBJ loc63;
GIN_OBJ loc64;
GIN_OBJ loc65;
GIN_OBJ loc66;
GIN_OBJ loc67;
GIN_OBJ loc68;
GIN_OBJ loc69;
GIN_OBJ loc70;
GIN_OBJ loc71;
GIN_OBJ loc72;
GIN_OBJ loc73;
GIN_OBJ loc74;
GIN_OBJ loc75;
GIN_OBJ loc76;
GIN_OBJ loc77;
GIN_OBJ loc78;
GIN_OBJ loc79;
GIN_OBJ loc80;
GIN_OBJ loc81;
GIN_OBJ loc82;
GIN_OBJ loc83;
GIN_OBJ loc84;
GIN_OBJ loc85;
GIN_OBJ loc86;
GIN_OBJ loc87;
GIN_OBJ loc88;
GIN_OBJ loc89;
GIN_OBJ loc90;
GIN_OBJ loc91;
GIN_OBJ loc92;
GIN_OBJ loc93;
GIN_OBJ loc94;
GIN_OBJ loc95;
GIN_OBJ loc96;
GIN_OBJ loc97;
GIN_OBJ loc98;
GIN_OBJ loc99;
GIN_OBJ loc100;
GIN_OBJ loc101;
GIN_OBJ loc102;
GIN_OBJ loc103;
GIN_OBJ loc104;
GIN_OBJ loc105;
GIN_OBJ loc106;
GIN_OBJ loc107;
GIN_OBJ loc108;
GIN_OBJ loc109;
GIN_OBJ loc110;
GIN_OBJ loc111;
GIN_OBJ loc112;
GIN_OBJ loc113;
GIN_OBJ loc114;
GIN_OBJ loc115;
GIN_OBJ loc116;
GIN_OBJ loc117;
GIN_OBJ loc118;
GIN_OBJ loc119;
GIN_OBJ loc120;
GIN_OBJ loc121;
GIN_OBJ loc122;
GIN_OBJ loc123;
GIN_OBJ loc124;
GIN_OBJ loc125;
GIN_OBJ loc126;
GIN_OBJ loc127;
GIN_OBJ loc128;
GIN_OBJ loc129;
GIN_OBJ loc130;
GIN_OBJ loc131;
GIN_OBJ loc132;
GIN_OBJ loc133;
GIN_OBJ loc134;
GIN_OBJ loc135;
GIN_OBJ loc136;
GIN_OBJ loc137;
GIN_OBJ loc138;
GIN_OBJ loc139;
GIN_OBJ loc140;
GIN_OBJ loc141;
GIN_OBJ loc142;
GIN_OBJ loc143;
GIN_OBJ loc144;
GIN_OBJ loc145;
GIN_OBJ loc146;
GIN_OBJ loc147;
GIN_OBJ loc148;
GIN_OBJ loc149;
GIN_OBJ loc150;
GIN_OBJ loc151;
GIN_OBJ loc152;
GIN_OBJ loc153;
GIN_OBJ loc154;
GIN_OBJ loc155;
GIN_OBJ loc156;
GIN_OBJ loc157;
GIN_OBJ loc158;
GIN_OBJ loc159;
GIN_OBJ loc160;
GIN_OBJ loc161;
GIN_OBJ loc162;
GIN_OBJ loc163;
GIN_OBJ loc164;
GIN_OBJ loc165;
GIN_OBJ loc166;
GIN_OBJ loc167;
GIN_OBJ loc168;
GIN_OBJ loc169;
GIN_OBJ loc170;
GIN_OBJ loc171;
GIN_OBJ loc172;
GIN_OBJ loc173;
GIN_OBJ loc174;
GIN_OBJ loc175;
GIN_OBJ loc176;
GIN_OBJ loc177;
GIN_OBJ loc178;
GIN_OBJ loc179;
GIN_OBJ loc180;
GIN_OBJ loc181;
GIN_OBJ loc182;
GIN_OBJ loc183;
GIN_OBJ loc184;
GIN_OBJ loc185;
GIN_OBJ loc186;
GIN_OBJ loc187;
GIN_OBJ loc188;
GIN_OBJ loc189;
GIN_OBJ loc190;
GIN_OBJ loc191;
GIN_OBJ loc192;
GIN_OBJ loc193;
GIN_OBJ loc194;
GIN_OBJ loc195;
GIN_OBJ loc196;
GIN_OBJ loc197;
GIN_OBJ loc198;
GIN_OBJ loc199;
GIN_OBJ loc200;
GIN_OBJ loc201;
GIN_OBJ loc202;
GIN_OBJ loc203;
GIN_OBJ loc204;
GIN_OBJ loc205;
GIN_OBJ loc206;
GIN_OBJ loc207;
GIN_OBJ loc208;
GIN_OBJ loc209;
GIN_OBJ loc210;
GIN_OBJ loc211;
GIN_OBJ loc212;
GIN_OBJ loc213;
GIN_OBJ loc214;
GIN_OBJ loc215;
GIN_OBJ loc216;
GIN_OBJ loc217;
GIN_OBJ loc218;
GIN_OBJ loc219;
GIN_OBJ loc220;
GIN_OBJ loc221;
GIN_OBJ loc222;
GIN_OBJ loc223;
GIN_OBJ loc224;
GIN_OBJ loc225;
GIN_OBJ loc226;
GIN_OBJ loc227;
GIN_OBJ loc228;
GIN_OBJ loc229;
GIN_OBJ loc230;
GIN_OBJ loc231;
GIN_OBJ loc232;
GIN_OBJ loc233;
GIN_OBJ loc234;
GIN_OBJ loc235;
GIN_OBJ loc236;
GIN_OBJ loc237;
GIN_OBJ loc238;
GIN_OBJ loc239;
GIN_OBJ loc240;
GIN_OBJ loc241;
GIN_OBJ loc242;
GIN_OBJ loc243;
GIN_OBJ loc244;
GIN_OBJ loc245;
GIN_OBJ loc246;
GIN_OBJ loc247;
GIN_OBJ loc248;
GIN_OBJ loc249;
GIN_OBJ loc250;
GIN_OBJ loc251;
GIN_OBJ loc252;
GIN_OBJ loc253;
GIN_OBJ loc254;
GIN_OBJ loc255;
GIN_OBJ loc256;
GIN_OBJ loc257;
GIN_OBJ loc258;
GIN_OBJ loc259;
GIN_OBJ loc260;
GIN_OBJ loc261;
GIN_OBJ loc262;
GIN_OBJ loc263;
GIN_OBJ loc264;
GIN_OBJ loc265;
GIN_OBJ loc266;
GIN_OBJ loc267;
GIN_OBJ loc268;
GIN_OBJ loc269;
GIN_OBJ loc270;
GIN_OBJ loc271;
GIN_OBJ loc272;
GIN_OBJ loc273;
GIN_OBJ loc274;
GIN_OBJ loc275;
GIN_OBJ loc276;
GIN_OBJ loc277;
GIN_OBJ loc278;
GIN_OBJ loc279;
GIN_OBJ loc280;
GIN_OBJ loc281;
GIN_OBJ loc282;
GIN_OBJ loc283;
GIN_OBJ loc284;
GIN_OBJ loc285;
GIN_OBJ loc286;
GIN_OBJ loc287;
GIN_OBJ loc288;
GIN_OBJ loc289;
GIN_OBJ loc290;
GIN_OBJ loc291;
GIN_OBJ loc292;
GIN_OBJ loc293;
GIN_OBJ loc294;
GIN_OBJ loc295;
GIN_OBJ loc296;
GIN_OBJ loc297;
GIN_OBJ loc298;
GIN_OBJ loc299;
GIN_OBJ loc300;
GIN_OBJ loc301;
GIN_OBJ loc302;
GIN_OBJ loc303;
GIN_OBJ loc304;
GIN_OBJ loc305;
GIN_OBJ loc306;
GIN_OBJ loc307;
GIN_OBJ loc308;
GIN_OBJ loc309;
GIN_OBJ loc310;
GIN_OBJ loc311;
GIN_OBJ loc312;
GIN_OBJ loc313;
GIN_OBJ loc314;
GIN_OBJ loc315;
GIN_OBJ loc316;
GIN_OBJ loc317;
GIN_OBJ loc318;
GIN_OBJ loc319;
GIN_OBJ loc320;
GIN_OBJ loc321;
GIN_OBJ loc322;
GIN_OBJ loc323;
GIN_OBJ loc324;
GIN_OBJ loc325;
GIN_OBJ loc326;
GIN_OBJ loc327;
GIN_OBJ loc328;
GIN_OBJ loc329;
GIN_OBJ loc330;
GIN_OBJ loc331;
GIN_OBJ loc332;
GIN_OBJ loc333;
GIN_OBJ loc334;
GIN_OBJ loc335;
GIN_OBJ loc336;
GIN_OBJ loc337;
GIN_OBJ loc338;
GIN_OBJ loc339;
GIN_OBJ loc340;
GIN_OBJ loc341;
GIN_OBJ loc342;
GIN_OBJ loc343;
GIN_OBJ loc344;
GIN_OBJ loc345;
GIN_OBJ loc346;
GIN_OBJ loc347;
GIN_OBJ loc348;
GIN_OBJ loc349;
GIN_OBJ loc350;
GIN_OBJ loc351;
GIN_OBJ loc352;
GIN_OBJ loc353;
GIN_OBJ loc354;
GIN_OBJ loc355;
GIN_OBJ loc356;
GIN_OBJ loc357;
GIN_OBJ loc358;
GIN_OBJ loc359;
GIN_OBJ loc360;
GIN_OBJ loc361;
GIN_OBJ loc362;
GIN_OBJ loc363;
GIN_OBJ loc364;
GIN_OBJ loc365;
GIN_OBJ loc366;
GIN_OBJ loc367;
GIN_OBJ loc368;
GIN_OBJ loc369;
GIN_OBJ loc370;
GIN_OBJ loc371;
GIN_OBJ loc372;
GIN_OBJ loc373;
GIN_OBJ loc374;
GIN_OBJ loc375;
GIN_OBJ loc376;
GIN_OBJ loc377;
GIN_OBJ loc378;
GIN_OBJ loc379;
GIN_OBJ loc380;
GIN_OBJ loc381;
GIN_OBJ loc382;
GIN_OBJ loc383;
GIN_OBJ loc384;
GIN_OBJ loc385;
GIN_OBJ loc386;
GIN_OBJ loc387;
GIN_OBJ loc388;
GIN_OBJ loc389;
GIN_OBJ loc390;
GIN_OBJ loc391;
GIN_OBJ loc392;
GIN_OBJ loc393;
GIN_OBJ loc394;
GIN_OBJ loc395;
GIN_OBJ loc396;
GIN_OBJ loc397;
GIN_OBJ loc398;
GIN_OBJ loc399;
GIN_OBJ loc400;
GIN_OBJ loc401;
GIN_OBJ loc402;
GIN_OBJ loc403;
GIN_OBJ loc404;
GIN_OBJ loc405;
GIN_OBJ loc406;
GIN_OBJ loc407;
GIN_OBJ loc408;
GIN_OBJ loc409;
GIN_OBJ loc410;
GIN_OBJ loc411;
GIN_OBJ loc412;
GIN_OBJ loc413;
GIN_OBJ loc414;
GIN_OBJ loc415;
GIN_OBJ loc416;
GIN_OBJ loc417;
GIN_OBJ loc418;
GIN_OBJ loc419;
GIN_OBJ loc420;
GIN_OBJ loc421;
GIN_OBJ loc422;
GIN_OBJ loc423;
GIN_OBJ loc424;
GIN_OBJ loc425;
GIN_OBJ loc426;
GIN_OBJ loc427;
GIN_OBJ loc428;
GIN_OBJ loc429;
GIN_OBJ loc430;
GIN_OBJ loc431;
GIN_OBJ loc432;
GIN_OBJ loc433;
GIN_OBJ loc434;
GIN_OBJ loc435;
GIN_OBJ loc436;
GIN_OBJ loc437;
GIN_OBJ loc438;
GIN_OBJ loc439;
GIN_OBJ loc440;
GIN_OBJ loc441;
GIN_OBJ loc442;
GIN_OBJ loc443;
GIN_OBJ loc444;
GIN_OBJ loc445;
GIN_OBJ loc446;
GIN_OBJ loc447;
GIN_OBJ loc448;
GIN_OBJ loc449;
GIN_OBJ loc450;
GIN_OBJ loc451;
GIN_OBJ loc452;
GIN_OBJ loc453;
GIN_OBJ loc454;
GIN_OBJ loc455;
GIN_OBJ loc456;
GIN_OBJ loc457;
GIN_OBJ loc458;
GIN_OBJ loc459;
GIN_OBJ loc460;
GIN_OBJ loc461;
GIN_OBJ loc462;
GIN_OBJ loc463;
GIN_OBJ loc464;
GIN_OBJ loc465;
GIN_OBJ loc466;
GIN_OBJ loc467;
GIN_OBJ loc468;
GIN_OBJ loc469;
GIN_OBJ loc470;
GIN_OBJ loc471;
GIN_OBJ loc472;
GIN_OBJ loc473;
GIN_OBJ loc474;
GIN_OBJ loc475;
GIN_OBJ loc476;
GIN_OBJ loc477;
GIN_OBJ loc478;
GIN_OBJ loc479;
GIN_OBJ loc480;
GIN_OBJ loc481;
GIN_OBJ loc482;
GIN_OBJ loc483;
GIN_OBJ loc484;
GIN_OBJ loc485;
GIN_OBJ loc486;
GIN_OBJ loc487;
GIN_OBJ loc488;
GIN_OBJ loc489;
GIN_OBJ loc490;
GIN_OBJ loc491;
GIN_OBJ loc492;
GIN_OBJ loc493;
GIN_OBJ loc494;
GIN_OBJ loc495;
GIN_OBJ loc496;
GIN_OBJ loc497;
GIN_OBJ loc498;
GIN_OBJ loc499;
GIN_OBJ loc500;
GIN_OBJ loc501;
GIN_OBJ loc502;
GIN_OBJ loc503;
GIN_OBJ loc504;
GIN_OBJ loc505;
GIN_OBJ loc506;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
GIN_OBJ tmp7;
GIN_OBJ tmp8;
GIN_OBJ tmp9;
} Frame___MAIN;

#define ALLOCATE_FRAME___MAIN(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___MAIN));
#define DEALLOCATE_FRAME___MAIN(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
} Frame___Type_058_058make;

#define ALLOCATE_FRAME___Type_058_058make(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Type_058_058make));
#define DEALLOCATE_FRAME___Type_058_058make(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Type_058_058index;

#define ALLOCATE_FRAME___Type_058_058index(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Type_058_058index));
#define DEALLOCATE_FRAME___Type_058_058index(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Type_058_058eq_063;

#define ALLOCATE_FRAME___Type_058_058eq_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Type_058_058eq_063));
#define DEALLOCATE_FRAME___Type_058_058eq_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___Type_063;

#define ALLOCATE_FRAME___Type_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Type_063));
#define DEALLOCATE_FRAME___Type_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Ginger_058_058immediate_063;

#define ALLOCATE_FRAME___Ginger_058_058immediate_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Ginger_058_058immediate_063));
#define DEALLOCATE_FRAME___Ginger_058_058immediate_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
} Frame___Ginger_058_058im_045type;

#define ALLOCATE_FRAME___Ginger_058_058im_045type(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Ginger_058_058im_045type));
#define DEALLOCATE_FRAME___Ginger_058_058im_045type(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___Ginger_058_058im_045_062Binary;

#define ALLOCATE_FRAME___Ginger_058_058im_045_062Binary(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Ginger_058_058im_045_062Binary));
#define DEALLOCATE_FRAME___Ginger_058_058im_045_062Binary(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Ginger_058_058nim_045type;

#define ALLOCATE_FRAME___Ginger_058_058nim_045type(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Ginger_058_058nim_045type));
#define DEALLOCATE_FRAME___Ginger_058_058nim_045type(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___type;

#define ALLOCATE_FRAME___type(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___type));
#define DEALLOCATE_FRAME___type(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___type_045of;

#define ALLOCATE_FRAME___type_045of(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___type_045of));
#define DEALLOCATE_FRAME___type_045of(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
GIN_OBJ tmp7;
} Frame___object_045_062string;

#define ALLOCATE_FRAME___object_045_062string(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___object_045_062string));
#define DEALLOCATE_FRAME___object_045_062string(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ tmp0;
} Frame___object_045_062pretty_045string;

#define ALLOCATE_FRAME___object_045_062pretty_045string(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___object_045_062pretty_045string));
#define DEALLOCATE_FRAME___object_045_062pretty_045string(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ loc4;
GIN_OBJ loc5;
GIN_OBJ loc6;
GIN_OBJ loc7;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
GIN_OBJ tmp7;
GIN_OBJ tmp8;
GIN_OBJ tmp9;
GIN_OBJ tmp10;
GIN_OBJ tmp11;
} Frame___object_045_062pretty_045string_045internal;

#define ALLOCATE_FRAME___object_045_062pretty_045string_045internal(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___object_045_062pretty_045string_045internal));
#define DEALLOCATE_FRAME___object_045_062pretty_045string_045internal(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Ginger_058_058Symbol_045_062Number;

#define ALLOCATE_FRAME___Ginger_058_058Symbol_045_062Number(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Ginger_058_058Symbol_045_062Number));
#define DEALLOCATE_FRAME___Ginger_058_058Symbol_045_062Number(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___Ginger_058_058String_045_062Symbol;

#define ALLOCATE_FRAME___Ginger_058_058String_045_062Symbol(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Ginger_058_058String_045_062Symbol));
#define DEALLOCATE_FRAME___Ginger_058_058String_045_062Symbol(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
} Frame___Ginger_058_058Symbol_045_062String;

#define ALLOCATE_FRAME___Ginger_058_058Symbol_045_062String(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Ginger_058_058Symbol_045_062String));
#define DEALLOCATE_FRAME___Ginger_058_058Symbol_045_062String(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___Ginger_058_058bootstrap_045symbols;

#define ALLOCATE_FRAME___Ginger_058_058bootstrap_045symbols(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Ginger_058_058bootstrap_045symbols));
#define DEALLOCATE_FRAME___Ginger_058_058bootstrap_045symbols(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___eq_063;

#define ALLOCATE_FRAME___eq_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___eq_063));
#define DEALLOCATE_FRAME___eq_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___Binary_058_058make;

#define ALLOCATE_FRAME___Binary_058_058make(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Binary_058_058make));
#define DEALLOCATE_FRAME___Binary_058_058make(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___Binary_063;

#define ALLOCATE_FRAME___Binary_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Binary_063));
#define DEALLOCATE_FRAME___Binary_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___Binary_045_062Integer;

#define ALLOCATE_FRAME___Binary_045_062Integer(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Binary_045_062Integer));
#define DEALLOCATE_FRAME___Binary_045_062Integer(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___Binary_058_058length;

#define ALLOCATE_FRAME___Binary_058_058length(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Binary_058_058length));
#define DEALLOCATE_FRAME___Binary_058_058length(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ loc4;
GIN_OBJ loc5;
GIN_OBJ loc6;
GIN_OBJ loc7;
GIN_OBJ loc8;
GIN_OBJ loc9;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___Binary_058_058_043;

#define ALLOCATE_FRAME___Binary_058_058_043(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Binary_058_058_043));
#define DEALLOCATE_FRAME___Binary_058_058_043(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___Binary_058_058_045;

#define ALLOCATE_FRAME___Binary_058_058_045(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Binary_058_058_045));
#define DEALLOCATE_FRAME___Binary_058_058_045(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___Binary_058_058_042;

#define ALLOCATE_FRAME___Binary_058_058_042(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Binary_058_058_042));
#define DEALLOCATE_FRAME___Binary_058_058_042(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___Binary_058_058_047;

#define ALLOCATE_FRAME___Binary_058_058_047(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Binary_058_058_047));
#define DEALLOCATE_FRAME___Binary_058_058_047(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___Binary_058_058_062;

#define ALLOCATE_FRAME___Binary_058_058_062(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Binary_058_058_062));
#define DEALLOCATE_FRAME___Binary_058_058_062(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___Binary_058_058_062_061;

#define ALLOCATE_FRAME___Binary_058_058_062_061(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Binary_058_058_062_061));
#define DEALLOCATE_FRAME___Binary_058_058_062_061(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___Binary_058_058_060;

#define ALLOCATE_FRAME___Binary_058_058_060(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Binary_058_058_060));
#define DEALLOCATE_FRAME___Binary_058_058_060(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___Binary_058_058_060_061;

#define ALLOCATE_FRAME___Binary_058_058_060_061(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Binary_058_058_060_061));
#define DEALLOCATE_FRAME___Binary_058_058_060_061(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___Binary_058_058eq_063;

#define ALLOCATE_FRAME___Binary_058_058eq_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Binary_058_058eq_063));
#define DEALLOCATE_FRAME___Binary_058_058eq_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___Binary_058_058_033_061;

#define ALLOCATE_FRAME___Binary_058_058_033_061(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Binary_058_058_033_061));
#define DEALLOCATE_FRAME___Binary_058_058_033_061(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___Binary_058_058_060_060;

#define ALLOCATE_FRAME___Binary_058_058_060_060(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Binary_058_058_060_060));
#define DEALLOCATE_FRAME___Binary_058_058_060_060(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___Binary_058_058_060_060_060;

#define ALLOCATE_FRAME___Binary_058_058_060_060_060(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Binary_058_058_060_060_060));
#define DEALLOCATE_FRAME___Binary_058_058_060_060_060(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___Binary_058_058_062_062;

#define ALLOCATE_FRAME___Binary_058_058_062_062(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Binary_058_058_062_062));
#define DEALLOCATE_FRAME___Binary_058_058_062_062(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___Binary_058_058_062_062_062;

#define ALLOCATE_FRAME___Binary_058_058_062_062_062(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Binary_058_058_062_062_062));
#define DEALLOCATE_FRAME___Binary_058_058_062_062_062(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___Binary_045_062String;

#define ALLOCATE_FRAME___Binary_045_062String(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Binary_045_062String));
#define DEALLOCATE_FRAME___Binary_045_062String(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___bin;

#define ALLOCATE_FRAME___bin(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___bin));
#define DEALLOCATE_FRAME___bin(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame____043;

#define ALLOCATE_FRAME____043(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____043));
#define DEALLOCATE_FRAME____043(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame____045;

#define ALLOCATE_FRAME____045(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____045));
#define DEALLOCATE_FRAME____045(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame____042;

#define ALLOCATE_FRAME____042(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____042));
#define DEALLOCATE_FRAME____042(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame____047;

#define ALLOCATE_FRAME____047(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____047));
#define DEALLOCATE_FRAME____047(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame____060;

#define ALLOCATE_FRAME____060(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060));
#define DEALLOCATE_FRAME____060(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame____060_061;

#define ALLOCATE_FRAME____060_061(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060_061));
#define DEALLOCATE_FRAME____060_061(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame____062;

#define ALLOCATE_FRAME____062(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____062));
#define DEALLOCATE_FRAME____062(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame____062_061;

#define ALLOCATE_FRAME____062_061(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____062_061));
#define DEALLOCATE_FRAME____062_061(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame____061;

#define ALLOCATE_FRAME____061(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____061));
#define DEALLOCATE_FRAME____061(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___max;

#define ALLOCATE_FRAME___max(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___max));
#define DEALLOCATE_FRAME___max(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___min;

#define ALLOCATE_FRAME___min(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___min));
#define DEALLOCATE_FRAME___min(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___abs;

#define ALLOCATE_FRAME___abs(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___abs));
#define DEALLOCATE_FRAME___abs(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___modulo;

#define ALLOCATE_FRAME___modulo(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___modulo));
#define DEALLOCATE_FRAME___modulo(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___zero_063;

#define ALLOCATE_FRAME___zero_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___zero_063));
#define DEALLOCATE_FRAME___zero_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___positive_063;

#define ALLOCATE_FRAME___positive_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___positive_063));
#define DEALLOCATE_FRAME___positive_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___negative_063;

#define ALLOCATE_FRAME___negative_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___negative_063));
#define DEALLOCATE_FRAME___negative_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___odd_063;

#define ALLOCATE_FRAME___odd_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___odd_063));
#define DEALLOCATE_FRAME___odd_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___even_063;

#define ALLOCATE_FRAME___even_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___even_063));
#define DEALLOCATE_FRAME___even_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___remainder;

#define ALLOCATE_FRAME___remainder(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___remainder));
#define DEALLOCATE_FRAME___remainder(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___gcd;

#define ALLOCATE_FRAME___gcd(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___gcd));
#define DEALLOCATE_FRAME___gcd(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___Number_063;

#define ALLOCATE_FRAME___Number_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Number_063));
#define DEALLOCATE_FRAME___Number_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___nocall;

#define ALLOCATE_FRAME___nocall(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___nocall));
#define DEALLOCATE_FRAME___nocall(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___degree_045_062radian;

#define ALLOCATE_FRAME___degree_045_062radian(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___degree_045_062radian));
#define DEALLOCATE_FRAME___degree_045_062radian(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___sin;

#define ALLOCATE_FRAME___sin(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___sin));
#define DEALLOCATE_FRAME___sin(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___cos;

#define ALLOCATE_FRAME___cos(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___cos));
#define DEALLOCATE_FRAME___cos(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___expt;

#define ALLOCATE_FRAME___expt(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___expt));
#define DEALLOCATE_FRAME___expt(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___Fixnum_058_058make;

#define ALLOCATE_FRAME___Fixnum_058_058make(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Fixnum_058_058make));
#define DEALLOCATE_FRAME___Fixnum_058_058make(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___Fixnum_063;

#define ALLOCATE_FRAME___Fixnum_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Fixnum_063));
#define DEALLOCATE_FRAME___Fixnum_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Fixnum_045_062Binary;

#define ALLOCATE_FRAME___Fixnum_045_062Binary(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Fixnum_045_062Binary));
#define DEALLOCATE_FRAME___Fixnum_045_062Binary(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Fixnum_045_062String;

#define ALLOCATE_FRAME___Fixnum_045_062String(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Fixnum_045_062String));
#define DEALLOCATE_FRAME___Fixnum_045_062String(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Fixnum_045_062Flonum;

#define ALLOCATE_FRAME___Fixnum_045_062Flonum(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Fixnum_045_062Flonum));
#define DEALLOCATE_FRAME___Fixnum_045_062Flonum(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Fixnum_045_062Char;

#define ALLOCATE_FRAME___Fixnum_045_062Char(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Fixnum_045_062Char));
#define DEALLOCATE_FRAME___Fixnum_045_062Char(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Fixnum_058_058_043;

#define ALLOCATE_FRAME___Fixnum_058_058_043(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Fixnum_058_058_043));
#define DEALLOCATE_FRAME___Fixnum_058_058_043(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Fixnum_058_058_045;

#define ALLOCATE_FRAME___Fixnum_058_058_045(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Fixnum_058_058_045));
#define DEALLOCATE_FRAME___Fixnum_058_058_045(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Fixnum_058_058_047;

#define ALLOCATE_FRAME___Fixnum_058_058_047(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Fixnum_058_058_047));
#define DEALLOCATE_FRAME___Fixnum_058_058_047(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Fixnum_058_058_042;

#define ALLOCATE_FRAME___Fixnum_058_058_042(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Fixnum_058_058_042));
#define DEALLOCATE_FRAME___Fixnum_058_058_042(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Fixnum_058_058_060;

#define ALLOCATE_FRAME___Fixnum_058_058_060(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Fixnum_058_058_060));
#define DEALLOCATE_FRAME___Fixnum_058_058_060(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Fixnum_058_058_062;

#define ALLOCATE_FRAME___Fixnum_058_058_062(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Fixnum_058_058_062));
#define DEALLOCATE_FRAME___Fixnum_058_058_062(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Fixnum_058_058_062_061;

#define ALLOCATE_FRAME___Fixnum_058_058_062_061(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Fixnum_058_058_062_061));
#define DEALLOCATE_FRAME___Fixnum_058_058_062_061(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Fixnum_058_058_060_061;

#define ALLOCATE_FRAME___Fixnum_058_058_060_061(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Fixnum_058_058_060_061));
#define DEALLOCATE_FRAME___Fixnum_058_058_060_061(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Fixnum_058_058_061;

#define ALLOCATE_FRAME___Fixnum_058_058_061(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Fixnum_058_058_061));
#define DEALLOCATE_FRAME___Fixnum_058_058_061(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___Integer_063;

#define ALLOCATE_FRAME___Integer_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Integer_063));
#define DEALLOCATE_FRAME___Integer_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___Integer_045_062Binary;

#define ALLOCATE_FRAME___Integer_045_062Binary(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Integer_045_062Binary));
#define DEALLOCATE_FRAME___Integer_045_062Binary(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___Integer_045_062String;

#define ALLOCATE_FRAME___Integer_045_062String(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Integer_045_062String));
#define DEALLOCATE_FRAME___Integer_045_062String(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___Integer_045_062Flonum;

#define ALLOCATE_FRAME___Integer_045_062Flonum(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Integer_045_062Flonum));
#define DEALLOCATE_FRAME___Integer_045_062Flonum(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Integer_045_062Char;

#define ALLOCATE_FRAME___Integer_045_062Char(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Integer_045_062Char));
#define DEALLOCATE_FRAME___Integer_045_062Char(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___Integer_058_058_043;

#define ALLOCATE_FRAME___Integer_058_058_043(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Integer_058_058_043));
#define DEALLOCATE_FRAME___Integer_058_058_043(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___Integer_058_058_045;

#define ALLOCATE_FRAME___Integer_058_058_045(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Integer_058_058_045));
#define DEALLOCATE_FRAME___Integer_058_058_045(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___Integer_058_058_042;

#define ALLOCATE_FRAME___Integer_058_058_042(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Integer_058_058_042));
#define DEALLOCATE_FRAME___Integer_058_058_042(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___Integer_058_058_047;

#define ALLOCATE_FRAME___Integer_058_058_047(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Integer_058_058_047));
#define DEALLOCATE_FRAME___Integer_058_058_047(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___Integer_058_058_060;

#define ALLOCATE_FRAME___Integer_058_058_060(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Integer_058_058_060));
#define DEALLOCATE_FRAME___Integer_058_058_060(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___Integer_058_058_060_061;

#define ALLOCATE_FRAME___Integer_058_058_060_061(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Integer_058_058_060_061));
#define DEALLOCATE_FRAME___Integer_058_058_060_061(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___Integer_058_058_062;

#define ALLOCATE_FRAME___Integer_058_058_062(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Integer_058_058_062));
#define DEALLOCATE_FRAME___Integer_058_058_062(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___Integer_058_058_062_061;

#define ALLOCATE_FRAME___Integer_058_058_062_061(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Integer_058_058_062_061));
#define DEALLOCATE_FRAME___Integer_058_058_062_061(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___Integer_058_058_061;

#define ALLOCATE_FRAME___Integer_058_058_061(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Integer_058_058_061));
#define DEALLOCATE_FRAME___Integer_058_058_061(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___Flonum_063;

#define ALLOCATE_FRAME___Flonum_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Flonum_063));
#define DEALLOCATE_FRAME___Flonum_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___Flonum_045_062Binary;

#define ALLOCATE_FRAME___Flonum_045_062Binary(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Flonum_045_062Binary));
#define DEALLOCATE_FRAME___Flonum_045_062Binary(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Flonum_045_062String;

#define ALLOCATE_FRAME___Flonum_045_062String(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Flonum_045_062String));
#define DEALLOCATE_FRAME___Flonum_045_062String(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Flonum_045_062Integer;

#define ALLOCATE_FRAME___Flonum_045_062Integer(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Flonum_045_062Integer));
#define DEALLOCATE_FRAME___Flonum_045_062Integer(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Flonum_058_058_043;

#define ALLOCATE_FRAME___Flonum_058_058_043(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Flonum_058_058_043));
#define DEALLOCATE_FRAME___Flonum_058_058_043(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Flonum_058_058_045;

#define ALLOCATE_FRAME___Flonum_058_058_045(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Flonum_058_058_045));
#define DEALLOCATE_FRAME___Flonum_058_058_045(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Flonum_058_058_047;

#define ALLOCATE_FRAME___Flonum_058_058_047(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Flonum_058_058_047));
#define DEALLOCATE_FRAME___Flonum_058_058_047(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Flonum_058_058_042;

#define ALLOCATE_FRAME___Flonum_058_058_042(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Flonum_058_058_042));
#define DEALLOCATE_FRAME___Flonum_058_058_042(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Boolean_063;

#define ALLOCATE_FRAME___Boolean_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Boolean_063));
#define DEALLOCATE_FRAME___Boolean_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Boolean_045_062Binary;

#define ALLOCATE_FRAME___Boolean_045_062Binary(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Boolean_045_062Binary));
#define DEALLOCATE_FRAME___Boolean_045_062Binary(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___Boolean_045_062String;

#define ALLOCATE_FRAME___Boolean_045_062String(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Boolean_045_062String));
#define DEALLOCATE_FRAME___Boolean_045_062String(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___not;

#define ALLOCATE_FRAME___not(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___not));
#define DEALLOCATE_FRAME___not(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___true_063;

#define ALLOCATE_FRAME___true_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___true_063));
#define DEALLOCATE_FRAME___true_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___false_063;

#define ALLOCATE_FRAME___false_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___false_063));
#define DEALLOCATE_FRAME___false_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___Cons_063;

#define ALLOCATE_FRAME___Cons_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Cons_063));
#define DEALLOCATE_FRAME___Cons_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___bcons_063;

#define ALLOCATE_FRAME___bcons_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___bcons_063));
#define DEALLOCATE_FRAME___bcons_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Null_063;

#define ALLOCATE_FRAME___Null_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Null_063));
#define DEALLOCATE_FRAME___Null_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___empty_063;

#define ALLOCATE_FRAME___empty_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___empty_063));
#define DEALLOCATE_FRAME___empty_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___list_063;

#define ALLOCATE_FRAME___list_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___list_063));
#define DEALLOCATE_FRAME___list_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___pair;

#define ALLOCATE_FRAME___pair(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___pair));
#define DEALLOCATE_FRAME___pair(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ arg2;
GIN_OBJ tmp0;
} Frame___cons;

#define ALLOCATE_FRAME___cons(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___cons));
#define DEALLOCATE_FRAME___cons(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ arg2;
GIN_OBJ loc0;
GIN_OBJ tmp0;
} Frame___bcons;

#define ALLOCATE_FRAME___bcons(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___bcons));
#define DEALLOCATE_FRAME___bcons(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___first;

#define ALLOCATE_FRAME___first(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___first));
#define DEALLOCATE_FRAME___first(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___properties;

#define ALLOCATE_FRAME___properties(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___properties));
#define DEALLOCATE_FRAME___properties(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___second_042;

#define ALLOCATE_FRAME___second_042(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___second_042));
#define DEALLOCATE_FRAME___second_042(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___first_033;

#define ALLOCATE_FRAME___first_033(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___first_033));
#define DEALLOCATE_FRAME___first_033(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___properties_033;

#define ALLOCATE_FRAME___properties_033(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___properties_033));
#define DEALLOCATE_FRAME___properties_033(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___second_042_033;

#define ALLOCATE_FRAME___second_042_033(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___second_042_033));
#define DEALLOCATE_FRAME___second_042_033(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___nth;

#define ALLOCATE_FRAME___nth(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___nth));
#define DEALLOCATE_FRAME___nth(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___second;

#define ALLOCATE_FRAME___second(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___second));
#define DEALLOCATE_FRAME___second(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___third;

#define ALLOCATE_FRAME___third(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___third));
#define DEALLOCATE_FRAME___third(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___fourth;

#define ALLOCATE_FRAME___fourth(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___fourth));
#define DEALLOCATE_FRAME___fourth(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___fifth;

#define ALLOCATE_FRAME___fifth(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___fifth));
#define DEALLOCATE_FRAME___fifth(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___sixth;

#define ALLOCATE_FRAME___sixth(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___sixth));
#define DEALLOCATE_FRAME___sixth(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___seventh;

#define ALLOCATE_FRAME___seventh(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___seventh));
#define DEALLOCATE_FRAME___seventh(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___eigth;

#define ALLOCATE_FRAME___eigth(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___eigth));
#define DEALLOCATE_FRAME___eigth(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___ninth;

#define ALLOCATE_FRAME___ninth(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___ninth));
#define DEALLOCATE_FRAME___ninth(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___nth_042;

#define ALLOCATE_FRAME___nth_042(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___nth_042));
#define DEALLOCATE_FRAME___nth_042(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___third_042;

#define ALLOCATE_FRAME___third_042(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___third_042));
#define DEALLOCATE_FRAME___third_042(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___fourth_042;

#define ALLOCATE_FRAME___fourth_042(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___fourth_042));
#define DEALLOCATE_FRAME___fourth_042(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___fifth_042;

#define ALLOCATE_FRAME___fifth_042(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___fifth_042));
#define DEALLOCATE_FRAME___fifth_042(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___sixth_042;

#define ALLOCATE_FRAME___sixth_042(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___sixth_042));
#define DEALLOCATE_FRAME___sixth_042(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___seventh_042;

#define ALLOCATE_FRAME___seventh_042(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___seventh_042));
#define DEALLOCATE_FRAME___seventh_042(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___eigth_042;

#define ALLOCATE_FRAME___eigth_042(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___eigth_042));
#define DEALLOCATE_FRAME___eigth_042(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___ninth_042;

#define ALLOCATE_FRAME___ninth_042(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___ninth_042));
#define DEALLOCATE_FRAME___ninth_042(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___last;

#define ALLOCATE_FRAME___last(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___last));
#define DEALLOCATE_FRAME___last(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___last_042;

#define ALLOCATE_FRAME___last_042(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___last_042));
#define DEALLOCATE_FRAME___last_042(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___length;

#define ALLOCATE_FRAME___length(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___length));
#define DEALLOCATE_FRAME___length(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___append;

#define ALLOCATE_FRAME___append(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___append));
#define DEALLOCATE_FRAME___append(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
} Frame___reverse;

#define ALLOCATE_FRAME___reverse(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___reverse));
#define DEALLOCATE_FRAME___reverse(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___list;

#define ALLOCATE_FRAME___list(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___list));
#define DEALLOCATE_FRAME___list(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___contains_063;

#define ALLOCATE_FRAME___contains_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___contains_063));
#define DEALLOCATE_FRAME___contains_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
GIN_OBJ tmp7;
GIN_OBJ tmp8;
GIN_OBJ tmp9;
} Frame___split_045list;

#define ALLOCATE_FRAME___split_045list(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___split_045list));
#define DEALLOCATE_FRAME___split_045list(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___List_058_058duplicate;

#define ALLOCATE_FRAME___List_058_058duplicate(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___List_058_058duplicate));
#define DEALLOCATE_FRAME___List_058_058duplicate(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___Char_063;

#define ALLOCATE_FRAME___Char_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Char_063));
#define DEALLOCATE_FRAME___Char_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Char_045_062Binary;

#define ALLOCATE_FRAME___Char_045_062Binary(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Char_045_062Binary));
#define DEALLOCATE_FRAME___Char_045_062Binary(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___Char_045_062String;

#define ALLOCATE_FRAME___Char_045_062String(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Char_045_062String));
#define DEALLOCATE_FRAME___Char_045_062String(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Char_045_062Integer;

#define ALLOCATE_FRAME___Char_045_062Integer(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Char_045_062Integer));
#define DEALLOCATE_FRAME___Char_045_062Integer(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Char_058_058eq_063;

#define ALLOCATE_FRAME___Char_058_058eq_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Char_058_058eq_063));
#define DEALLOCATE_FRAME___Char_058_058eq_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Char_058_058alphabetic_063;

#define ALLOCATE_FRAME___Char_058_058alphabetic_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Char_058_058alphabetic_063));
#define DEALLOCATE_FRAME___Char_058_058alphabetic_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Char_058_058numeric_063;

#define ALLOCATE_FRAME___Char_058_058numeric_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Char_058_058numeric_063));
#define DEALLOCATE_FRAME___Char_058_058numeric_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Char_058_058whitespace_063;

#define ALLOCATE_FRAME___Char_058_058whitespace_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Char_058_058whitespace_063));
#define DEALLOCATE_FRAME___Char_058_058whitespace_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___Char_058_058upper_045case_063;

#define ALLOCATE_FRAME___Char_058_058upper_045case_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Char_058_058upper_045case_063));
#define DEALLOCATE_FRAME___Char_058_058upper_045case_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___Char_058_058lower_045case_063;

#define ALLOCATE_FRAME___Char_058_058lower_045case_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Char_058_058lower_045case_063));
#define DEALLOCATE_FRAME___Char_058_058lower_045case_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___Char_058_058upcase;

#define ALLOCATE_FRAME___Char_058_058upcase(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Char_058_058upcase));
#define DEALLOCATE_FRAME___Char_058_058upcase(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___Char_058_058downcase;

#define ALLOCATE_FRAME___Char_058_058downcase(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Char_058_058downcase));
#define DEALLOCATE_FRAME___Char_058_058downcase(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___Symbol_063;

#define ALLOCATE_FRAME___Symbol_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Symbol_063));
#define DEALLOCATE_FRAME___Symbol_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Symbol_045_062Binary;

#define ALLOCATE_FRAME___Symbol_045_062Binary(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Symbol_045_062Binary));
#define DEALLOCATE_FRAME___Symbol_045_062Binary(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Symbol_045_062String;

#define ALLOCATE_FRAME___Symbol_045_062String(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Symbol_045_062String));
#define DEALLOCATE_FRAME___Symbol_045_062String(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Symbol_058_058eq_063;

#define ALLOCATE_FRAME___Symbol_058_058eq_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Symbol_058_058eq_063));
#define DEALLOCATE_FRAME___Symbol_058_058eq_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Label_063;

#define ALLOCATE_FRAME___Label_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Label_063));
#define DEALLOCATE_FRAME___Label_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Label_058_058eq_063;

#define ALLOCATE_FRAME___Label_058_058eq_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Label_058_058eq_063));
#define DEALLOCATE_FRAME___Label_058_058eq_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ tmp0;
} Frame___Label_045_062String;

#define ALLOCATE_FRAME___Label_045_062String(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Label_045_062String));
#define DEALLOCATE_FRAME___Label_045_062String(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ tmp0;
} Frame___Ginger_058_058String_045_062Label;

#define ALLOCATE_FRAME___Ginger_058_058String_045_062Label(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Ginger_058_058String_045_062Label));
#define DEALLOCATE_FRAME___Ginger_058_058String_045_062Label(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ tmp0;
} Frame___String_058_058make;

#define ALLOCATE_FRAME___String_058_058make(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_058_058make));
#define DEALLOCATE_FRAME___String_058_058make(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___String_058_058string;

#define ALLOCATE_FRAME___String_058_058string(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_058_058string));
#define DEALLOCATE_FRAME___String_058_058string(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ arg2;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
} Frame___String_058_058join;

#define ALLOCATE_FRAME___String_058_058join(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_058_058join));
#define DEALLOCATE_FRAME___String_058_058join(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___String_063;

#define ALLOCATE_FRAME___String_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_063));
#define DEALLOCATE_FRAME___String_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___String_045_062Binary;

#define ALLOCATE_FRAME___String_045_062Binary(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_045_062Binary));
#define DEALLOCATE_FRAME___String_045_062Binary(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___String_058_058length;

#define ALLOCATE_FRAME___String_058_058length(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_058_058length));
#define DEALLOCATE_FRAME___String_058_058length(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___String_058_058nth;

#define ALLOCATE_FRAME___String_058_058nth(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_058_058nth));
#define DEALLOCATE_FRAME___String_058_058nth(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___String_058_058first;

#define ALLOCATE_FRAME___String_058_058first(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_058_058first));
#define DEALLOCATE_FRAME___String_058_058first(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___String_058_058last;

#define ALLOCATE_FRAME___String_058_058last(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_058_058last));
#define DEALLOCATE_FRAME___String_058_058last(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ arg2;
GIN_OBJ tmp0;
} Frame___String_058_058nth_033;

#define ALLOCATE_FRAME___String_058_058nth_033(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_058_058nth_033));
#define DEALLOCATE_FRAME___String_058_058nth_033(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___String_058_058eq_063;

#define ALLOCATE_FRAME___String_058_058eq_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_058_058eq_063));
#define DEALLOCATE_FRAME___String_058_058eq_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ arg2;
GIN_OBJ arg3;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___String_058_058compare;

#define ALLOCATE_FRAME___String_058_058compare(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_058_058compare));
#define DEALLOCATE_FRAME___String_058_058compare(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ arg2;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
} Frame___String_058_058substring;

#define ALLOCATE_FRAME___String_058_058substring(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_058_058substring));
#define DEALLOCATE_FRAME___String_058_058substring(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ loc4;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___String_058_058append;

#define ALLOCATE_FRAME___String_058_058append(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_058_058append));
#define DEALLOCATE_FRAME___String_058_058append(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___String_058_058put_045string;

#define ALLOCATE_FRAME___String_058_058put_045string(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_058_058put_045string));
#define DEALLOCATE_FRAME___String_058_058put_045string(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___String_058_058replace;

#define ALLOCATE_FRAME___String_058_058replace(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_058_058replace));
#define DEALLOCATE_FRAME___String_058_058replace(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
} Frame___String_058_058split;

#define ALLOCATE_FRAME___String_058_058split(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_058_058split));
#define DEALLOCATE_FRAME___String_058_058split(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
} Frame___split;

#define ALLOCATE_FRAME___split(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___split));
#define DEALLOCATE_FRAME___split(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___base_045name;

#define ALLOCATE_FRAME___base_045name(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___base_045name));
#define DEALLOCATE_FRAME___base_045name(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___Vector_058_058make;

#define ALLOCATE_FRAME___Vector_058_058make(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Vector_058_058make));
#define DEALLOCATE_FRAME___Vector_058_058make(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ tmp0;
} Frame___Vector_058_058push;

#define ALLOCATE_FRAME___Vector_058_058push(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Vector_058_058push));
#define DEALLOCATE_FRAME___Vector_058_058push(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___Vector_063;

#define ALLOCATE_FRAME___Vector_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Vector_063));
#define DEALLOCATE_FRAME___Vector_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Vector_058_058get;

#define ALLOCATE_FRAME___Vector_058_058get(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Vector_058_058get));
#define DEALLOCATE_FRAME___Vector_058_058get(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ arg2;
GIN_OBJ tmp0;
} Frame___Vector_058_058set;

#define ALLOCATE_FRAME___Vector_058_058set(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Vector_058_058set));
#define DEALLOCATE_FRAME___Vector_058_058set(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Vector_058_058length;

#define ALLOCATE_FRAME___Vector_058_058length(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Vector_058_058length));
#define DEALLOCATE_FRAME___Vector_058_058length(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___Vector_045_062list;

#define ALLOCATE_FRAME___Vector_045_062list(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Vector_045_062list));
#define DEALLOCATE_FRAME___Vector_045_062list(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___Vector_058_058fill;

#define ALLOCATE_FRAME___Vector_058_058fill(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Vector_058_058fill));
#define DEALLOCATE_FRAME___Vector_058_058fill(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Vector_045_062String;

#define ALLOCATE_FRAME___Vector_045_062String(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Vector_045_062String));
#define DEALLOCATE_FRAME___Vector_045_062String(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Vector_058_058first;

#define ALLOCATE_FRAME___Vector_058_058first(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Vector_058_058first));
#define DEALLOCATE_FRAME___Vector_058_058first(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Vector_058_058last;

#define ALLOCATE_FRAME___Vector_058_058last(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Vector_058_058last));
#define DEALLOCATE_FRAME___Vector_058_058last(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Vector_058_058pop;

#define ALLOCATE_FRAME___Vector_058_058pop(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Vector_058_058pop));
#define DEALLOCATE_FRAME___Vector_058_058pop(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ loc4;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___Dict_058_058make;

#define ALLOCATE_FRAME___Dict_058_058make(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Dict_058_058make));
#define DEALLOCATE_FRAME___Dict_058_058make(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___Dict_045_062String;

#define ALLOCATE_FRAME___Dict_045_062String(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Dict_045_062String));
#define DEALLOCATE_FRAME___Dict_045_062String(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___Dict_063;

#define ALLOCATE_FRAME___Dict_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Dict_063));
#define DEALLOCATE_FRAME___Dict_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Dict_045_062keys;

#define ALLOCATE_FRAME___Dict_045_062keys(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Dict_045_062keys));
#define DEALLOCATE_FRAME___Dict_045_062keys(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ arg2;
GIN_OBJ loc0;
GIN_OBJ tmp0;
} Frame___Dict_058_058set;

#define ALLOCATE_FRAME___Dict_058_058set(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Dict_058_058set));
#define DEALLOCATE_FRAME___Dict_058_058set(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___Dict_058_058get;

#define ALLOCATE_FRAME___Dict_058_058get(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Dict_058_058get));
#define DEALLOCATE_FRAME___Dict_058_058get(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___Dict_058_058contains_063;

#define ALLOCATE_FRAME___Dict_058_058contains_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Dict_058_058contains_063));
#define DEALLOCATE_FRAME___Dict_058_058contains_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___Dict_058_058remove;

#define ALLOCATE_FRAME___Dict_058_058remove(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Dict_058_058remove));
#define DEALLOCATE_FRAME___Dict_058_058remove(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___Dict_058_058clear;

#define ALLOCATE_FRAME___Dict_058_058clear(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Dict_058_058clear));
#define DEALLOCATE_FRAME___Dict_058_058clear(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___Dict_058_058size;

#define ALLOCATE_FRAME___Dict_058_058size(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Dict_058_058size));
#define DEALLOCATE_FRAME___Dict_058_058size(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___Function_063;

#define ALLOCATE_FRAME___Function_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Function_063));
#define DEALLOCATE_FRAME___Function_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Function_045_062String;

#define ALLOCATE_FRAME___Function_045_062String(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Function_045_062String));
#define DEALLOCATE_FRAME___Function_045_062String(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Null_045_062Binary;

#define ALLOCATE_FRAME___Null_045_062Binary(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Null_045_062Binary));
#define DEALLOCATE_FRAME___Null_045_062Binary(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___Foreign_045_062String;

#define ALLOCATE_FRAME___Foreign_045_062String(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Foreign_045_062String));
#define DEALLOCATE_FRAME___Foreign_045_062String(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___input_045stream_063;

#define ALLOCATE_FRAME___input_045stream_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___input_045stream_063));
#define DEALLOCATE_FRAME___input_045stream_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___output_045stream_063;

#define ALLOCATE_FRAME___output_045stream_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___output_045stream_063));
#define DEALLOCATE_FRAME___output_045stream_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___open_045file;

#define ALLOCATE_FRAME___open_045file(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___open_045file));
#define DEALLOCATE_FRAME___open_045file(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___open_045input_045file;

#define ALLOCATE_FRAME___open_045input_045file(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___open_045input_045file));
#define DEALLOCATE_FRAME___open_045input_045file(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___open_045output_045file;

#define ALLOCATE_FRAME___open_045output_045file(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___open_045output_045file));
#define DEALLOCATE_FRAME___open_045output_045file(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___close_045stream;

#define ALLOCATE_FRAME___close_045stream(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___close_045stream));
#define DEALLOCATE_FRAME___close_045stream(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___close_045input_045stream;

#define ALLOCATE_FRAME___close_045input_045stream(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___close_045input_045stream));
#define DEALLOCATE_FRAME___close_045input_045stream(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___close_045output_045stream;

#define ALLOCATE_FRAME___close_045output_045stream(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___close_045output_045stream));
#define DEALLOCATE_FRAME___close_045output_045stream(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___get_045char;

#define ALLOCATE_FRAME___get_045char(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___get_045char));
#define DEALLOCATE_FRAME___get_045char(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ tmp0;
} Frame___peek_045char;

#define ALLOCATE_FRAME___peek_045char(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___peek_045char));
#define DEALLOCATE_FRAME___peek_045char(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___unget_045char;

#define ALLOCATE_FRAME___unget_045char(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___unget_045char));
#define DEALLOCATE_FRAME___unget_045char(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___eof_045object_063;

#define ALLOCATE_FRAME___eof_045object_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___eof_045object_063));
#define DEALLOCATE_FRAME___eof_045object_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___char_045ready_063;

#define ALLOCATE_FRAME___char_045ready_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___char_045ready_063));
#define DEALLOCATE_FRAME___char_045ready_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___newline;

#define ALLOCATE_FRAME___newline(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___newline));
#define DEALLOCATE_FRAME___newline(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___write_045char;

#define ALLOCATE_FRAME___write_045char(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___write_045char));
#define DEALLOCATE_FRAME___write_045char(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ arg2;
GIN_OBJ tmp0;
} Frame___stream_045seek;

#define ALLOCATE_FRAME___stream_045seek(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___stream_045seek));
#define DEALLOCATE_FRAME___stream_045seek(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___stream_045tell;

#define ALLOCATE_FRAME___stream_045tell(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___stream_045tell));
#define DEALLOCATE_FRAME___stream_045tell(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Stream_063;

#define ALLOCATE_FRAME___Stream_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Stream_063));
#define DEALLOCATE_FRAME___Stream_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___String_045Stream_063;

#define ALLOCATE_FRAME___String_045Stream_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_045Stream_063));
#define DEALLOCATE_FRAME___String_045Stream_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___Generic_045Stream_063;

#define ALLOCATE_FRAME___Generic_045Stream_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Generic_045Stream_063));
#define DEALLOCATE_FRAME___Generic_045Stream_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___Stream_045_062String;

#define ALLOCATE_FRAME___Stream_045_062String(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Stream_045_062String));
#define DEALLOCATE_FRAME___Stream_045_062String(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___String_045Stream_045_062String;

#define ALLOCATE_FRAME___String_045Stream_045_062String(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_045Stream_045_062String));
#define DEALLOCATE_FRAME___String_045Stream_045_062String(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___open_045input_045string;

#define ALLOCATE_FRAME___open_045input_045string(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___open_045input_045string));
#define DEALLOCATE_FRAME___open_045input_045string(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ tmp0;
} Frame___open_045output_045string;

#define ALLOCATE_FRAME___open_045output_045string(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___open_045output_045string));
#define DEALLOCATE_FRAME___open_045output_045string(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___get_045output_045string;

#define ALLOCATE_FRAME___get_045output_045string(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___get_045output_045string));
#define DEALLOCATE_FRAME___get_045output_045string(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___string_045output_045stream_063;

#define ALLOCATE_FRAME___string_045output_045stream_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___string_045output_045stream_063));
#define DEALLOCATE_FRAME___string_045output_045stream_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ tmp0;
} Frame___write_045string_045stream;

#define ALLOCATE_FRAME___write_045string_045stream(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___write_045string_045stream));
#define DEALLOCATE_FRAME___write_045string_045stream(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___getenv;

#define ALLOCATE_FRAME___getenv(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___getenv));
#define DEALLOCATE_FRAME___getenv(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___file_045exists_063;

#define ALLOCATE_FRAME___file_045exists_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___file_045exists_063));
#define DEALLOCATE_FRAME___file_045exists_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___execute;

#define ALLOCATE_FRAME___execute(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___execute));
#define DEALLOCATE_FRAME___execute(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___gin_045debug;

#define ALLOCATE_FRAME___gin_045debug(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___gin_045debug));
#define DEALLOCATE_FRAME___gin_045debug(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___range;

#define ALLOCATE_FRAME___range(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___range));
#define DEALLOCATE_FRAME___range(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
GIN_OBJ tmp7;
} Frame___print_045term;

#define ALLOCATE_FRAME___print_045term(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___print_045term));
#define DEALLOCATE_FRAME___print_045term(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___print_045primitive;

#define ALLOCATE_FRAME___print_045primitive(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___print_045primitive));
#define DEALLOCATE_FRAME___print_045primitive(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
GIN_OBJ tmp7;
} Frame___print;

#define ALLOCATE_FRAME___print(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___print));
#define DEALLOCATE_FRAME___print(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
GIN_OBJ tmp7;
} Frame___println;

#define ALLOCATE_FRAME___println(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___println));
#define DEALLOCATE_FRAME___println(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
GIN_OBJ tmp7;
} Frame___write_045term;

#define ALLOCATE_FRAME___write_045term(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___write_045term));
#define DEALLOCATE_FRAME___write_045term(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___write_045primitive;

#define ALLOCATE_FRAME___write_045primitive(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___write_045primitive));
#define DEALLOCATE_FRAME___write_045primitive(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
GIN_OBJ tmp7;
} Frame___write;

#define ALLOCATE_FRAME___write(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___write));
#define DEALLOCATE_FRAME___write(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
GIN_OBJ tmp7;
} Frame___writeln;

#define ALLOCATE_FRAME___writeln(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___writeln));
#define DEALLOCATE_FRAME___writeln(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___print_045properties;

#define ALLOCATE_FRAME___print_045properties(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___print_045properties));
#define DEALLOCATE_FRAME___print_045properties(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
} Frame___print_045dictionary;

#define ALLOCATE_FRAME___print_045dictionary(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___print_045dictionary));
#define DEALLOCATE_FRAME___print_045dictionary(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___apply;

#define ALLOCATE_FRAME___apply(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___apply));
#define DEALLOCATE_FRAME___apply(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___command_045line;

#define ALLOCATE_FRAME___command_045line(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___command_045line));
#define DEALLOCATE_FRAME___command_045line(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ tmp0;
} Frame___exit;

#define ALLOCATE_FRAME___exit(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___exit));
#define DEALLOCATE_FRAME___exit(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___trait;

#define ALLOCATE_FRAME___trait(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___trait));
#define DEALLOCATE_FRAME___trait(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ arg2;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___trait_033;

#define ALLOCATE_FRAME___trait_033(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___trait_033));
#define DEALLOCATE_FRAME___trait_033(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame____060term_062_058_058function_045definition_063;

#define ALLOCATE_FRAME____060term_062_058_058function_045definition_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060term_062_058_058function_045definition_063));
#define DEALLOCATE_FRAME____060term_062_058_058function_045definition_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame____060term_062_058_058method_045definition_063;

#define ALLOCATE_FRAME____060term_062_058_058method_045definition_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060term_062_058_058method_045definition_063));
#define DEALLOCATE_FRAME____060term_062_058_058method_045definition_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
} Frame____060term_062_058_058get_045definition_045name;

#define ALLOCATE_FRAME____060term_062_058_058get_045definition_045name(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060term_062_058_058get_045definition_045name));
#define DEALLOCATE_FRAME____060term_062_058_058get_045definition_045name(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame____060term_062_058_058get_045definition_045body;

#define ALLOCATE_FRAME____060term_062_058_058get_045definition_045body(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060term_062_058_058get_045definition_045body));
#define DEALLOCATE_FRAME____060term_062_058_058get_045definition_045body(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame____060term_062_058_058get_045definition_045arguments;

#define ALLOCATE_FRAME____060term_062_058_058get_045definition_045arguments(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060term_062_058_058get_045definition_045arguments));
#define DEALLOCATE_FRAME____060term_062_058_058get_045definition_045arguments(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___Term_058_058head;

#define ALLOCATE_FRAME___Term_058_058head(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Term_058_058head));
#define DEALLOCATE_FRAME___Term_058_058head(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame____060term_062_058_058parent;

#define ALLOCATE_FRAME____060term_062_058_058parent(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060term_062_058_058parent));
#define DEALLOCATE_FRAME____060term_062_058_058parent(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame____060term_062_058_058get_045parent_045function;

#define ALLOCATE_FRAME____060term_062_058_058get_045parent_045function(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060term_062_058_058get_045parent_045function));
#define DEALLOCATE_FRAME____060term_062_058_058get_045parent_045function(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___get_045f;

#define ALLOCATE_FRAME___get_045f(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___get_045f));
#define DEALLOCATE_FRAME___get_045f(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame____060term_062_058_058definition_045symbol_063;

#define ALLOCATE_FRAME____060term_062_058_058definition_045symbol_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060term_062_058_058definition_045symbol_063));
#define DEALLOCATE_FRAME____060term_062_058_058definition_045symbol_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame____060term_062_058_058each_045loop_063;

#define ALLOCATE_FRAME____060term_062_058_058each_045loop_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060term_062_058_058each_045loop_063));
#define DEALLOCATE_FRAME____060term_062_058_058each_045loop_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame____060term_062_058_058definition_063;

#define ALLOCATE_FRAME____060term_062_058_058definition_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060term_062_058_058definition_063));
#define DEALLOCATE_FRAME____060term_062_058_058definition_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame____060term_062_058_058immutable_045definition_063;

#define ALLOCATE_FRAME____060term_062_058_058immutable_045definition_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060term_062_058_058immutable_045definition_063));
#define DEALLOCATE_FRAME____060term_062_058_058immutable_045definition_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame____060term_062_058_058quoted_045symbol_063;

#define ALLOCATE_FRAME____060term_062_058_058quoted_045symbol_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060term_062_058_058quoted_045symbol_063));
#define DEALLOCATE_FRAME____060term_062_058_058quoted_045symbol_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
} Frame___find_045named_045parameter;

#define ALLOCATE_FRAME___find_045named_045parameter(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___find_045named_045parameter));
#define DEALLOCATE_FRAME___find_045named_045parameter(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ loc4;
GIN_OBJ loc5;
GIN_OBJ loc6;
GIN_OBJ loc7;
GIN_OBJ loc8;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
GIN_OBJ tmp7;
GIN_OBJ tmp8;
} Frame___fix_045parameters;

#define ALLOCATE_FRAME___fix_045parameters(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___fix_045parameters));
#define DEALLOCATE_FRAME___fix_045parameters(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
} Frame___Char_045_062digit;

#define ALLOCATE_FRAME___Char_045_062digit(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Char_045_062digit));
#define DEALLOCATE_FRAME___Char_045_062digit(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___Char_058_058digit_063;

#define ALLOCATE_FRAME___Char_058_058digit_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Char_058_058digit_063));
#define DEALLOCATE_FRAME___Char_058_058digit_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___eos_045object_063;

#define ALLOCATE_FRAME___eos_045object_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___eos_045object_063));
#define DEALLOCATE_FRAME___eos_045object_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___eos_063;

#define ALLOCATE_FRAME___eos_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___eos_063));
#define DEALLOCATE_FRAME___eos_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Char_058_058eol_063;

#define ALLOCATE_FRAME___Char_058_058eol_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Char_058_058eol_063));
#define DEALLOCATE_FRAME___Char_058_058eol_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
} Frame___new_045string;

#define ALLOCATE_FRAME___new_045string(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___new_045string));
#define DEALLOCATE_FRAME___new_045string(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___String_058_058rest;

#define ALLOCATE_FRAME___String_058_058rest(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_058_058rest));
#define DEALLOCATE_FRAME___String_058_058rest(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___String_058_058Boolean_063;

#define ALLOCATE_FRAME___String_058_058Boolean_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_058_058Boolean_063));
#define DEALLOCATE_FRAME___String_058_058Boolean_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___String_045_062Boolean;

#define ALLOCATE_FRAME___String_045_062Boolean(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_045_062Boolean));
#define DEALLOCATE_FRAME___String_045_062Boolean(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___String_058_058ellipses_063;

#define ALLOCATE_FRAME___String_058_058ellipses_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_058_058ellipses_063));
#define DEALLOCATE_FRAME___String_058_058ellipses_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___String_058_058numeric_063;

#define ALLOCATE_FRAME___String_058_058numeric_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_058_058numeric_063));
#define DEALLOCATE_FRAME___String_058_058numeric_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___string_045positive_045numeric_063;

#define ALLOCATE_FRAME___string_045positive_045numeric_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___string_045positive_045numeric_063));
#define DEALLOCATE_FRAME___string_045positive_045numeric_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___String_045_062digits;

#define ALLOCATE_FRAME___String_045_062digits(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_045_062digits));
#define DEALLOCATE_FRAME___String_045_062digits(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ arg2;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
} Frame___string_045_062raw_045integer_045i;

#define ALLOCATE_FRAME___string_045_062raw_045integer_045i(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___string_045_062raw_045integer_045i));
#define DEALLOCATE_FRAME___string_045_062raw_045integer_045i(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___String_058_058digits_063;

#define ALLOCATE_FRAME___String_058_058digits_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_058_058digits_063));
#define DEALLOCATE_FRAME___String_058_058digits_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
} Frame___String_045_062Integer;

#define ALLOCATE_FRAME___String_045_062Integer(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_045_062Integer));
#define DEALLOCATE_FRAME___String_045_062Integer(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___String_058_058Integer_063;

#define ALLOCATE_FRAME___String_058_058Integer_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_058_058Integer_063));
#define DEALLOCATE_FRAME___String_058_058Integer_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___String_045_062Ratio;

#define ALLOCATE_FRAME___String_045_062Ratio(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_045_062Ratio));
#define DEALLOCATE_FRAME___String_045_062Ratio(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___String_058_058Ratio_063;

#define ALLOCATE_FRAME___String_058_058Ratio_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_058_058Ratio_063));
#define DEALLOCATE_FRAME___String_058_058Ratio_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ loc4;
GIN_OBJ loc5;
GIN_OBJ loc6;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
GIN_OBJ tmp7;
GIN_OBJ tmp8;
GIN_OBJ tmp9;
GIN_OBJ tmp10;
} Frame___String_045_062Scientific;

#define ALLOCATE_FRAME___String_045_062Scientific(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_045_062Scientific));
#define DEALLOCATE_FRAME___String_045_062Scientific(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___String_058_058scientific_063;

#define ALLOCATE_FRAME___String_058_058scientific_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_058_058scientific_063));
#define DEALLOCATE_FRAME___String_058_058scientific_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___String_058_058Rational_063;

#define ALLOCATE_FRAME___String_058_058Rational_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_058_058Rational_063));
#define DEALLOCATE_FRAME___String_058_058Rational_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___String_045_062Rational;

#define ALLOCATE_FRAME___String_045_062Rational(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_045_062Rational));
#define DEALLOCATE_FRAME___String_045_062Rational(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ loc4;
GIN_OBJ loc5;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___String_045_062Complex;

#define ALLOCATE_FRAME___String_045_062Complex(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_045_062Complex));
#define DEALLOCATE_FRAME___String_045_062Complex(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___String_058_058Complex_063;

#define ALLOCATE_FRAME___String_058_058Complex_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_058_058Complex_063));
#define DEALLOCATE_FRAME___String_058_058Complex_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___String_045_062Flonum;

#define ALLOCATE_FRAME___String_045_062Flonum(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_045_062Flonum));
#define DEALLOCATE_FRAME___String_045_062Flonum(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___String_045_062Symbol;

#define ALLOCATE_FRAME___String_045_062Symbol(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_045_062Symbol));
#define DEALLOCATE_FRAME___String_045_062Symbol(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___String_045_062Character;

#define ALLOCATE_FRAME___String_045_062Character(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_045_062Character));
#define DEALLOCATE_FRAME___String_045_062Character(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___String_058_058Character_063;

#define ALLOCATE_FRAME___String_058_058Character_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_058_058Character_063));
#define DEALLOCATE_FRAME___String_058_058Character_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___String_058_058Symbol_063;

#define ALLOCATE_FRAME___String_058_058Symbol_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_058_058Symbol_063));
#define DEALLOCATE_FRAME___String_058_058Symbol_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___char_045legal_045symbol_063;

#define ALLOCATE_FRAME___char_045legal_045symbol_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___char_045legal_045symbol_063));
#define DEALLOCATE_FRAME___char_045legal_045symbol_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___string_045legal_045symbol_063;

#define ALLOCATE_FRAME___string_045legal_045symbol_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___string_045legal_045symbol_063));
#define DEALLOCATE_FRAME___string_045legal_045symbol_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___String_045_062Value;

#define ALLOCATE_FRAME___String_045_062Value(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_045_062Value));
#define DEALLOCATE_FRAME___String_045_062Value(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___String_058_058Label_063;

#define ALLOCATE_FRAME___String_058_058Label_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___String_058_058Label_063));
#define DEALLOCATE_FRAME___String_058_058Label_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___include_045filename;

#define ALLOCATE_FRAME___include_045filename(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___include_045filename));
#define DEALLOCATE_FRAME___include_045filename(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
} Frame___open_045include_045file;

#define ALLOCATE_FRAME___open_045include_045file(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___open_045include_045file));
#define DEALLOCATE_FRAME___open_045include_045file(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ loc4;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___expand_045includes;

#define ALLOCATE_FRAME___expand_045includes(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___expand_045includes));
#define DEALLOCATE_FRAME___expand_045includes(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___include_063;

#define ALLOCATE_FRAME___include_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___include_063));
#define DEALLOCATE_FRAME___include_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___expand_045include;

#define ALLOCATE_FRAME___expand_045include(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___expand_045include));
#define DEALLOCATE_FRAME___expand_045include(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ arg2;
GIN_OBJ arg3;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame____060term_062_058_058make;

#define ALLOCATE_FRAME____060term_062_058_058make(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060term_062_058_058make));
#define DEALLOCATE_FRAME____060term_062_058_058make(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame____060group_062_058_058make;

#define ALLOCATE_FRAME____060group_062_058_058make(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060group_062_058_058make));
#define DEALLOCATE_FRAME____060group_062_058_058make(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___Group_063;

#define ALLOCATE_FRAME___Group_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Group_063));
#define DEALLOCATE_FRAME___Group_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ loc4;
GIN_OBJ loc5;
GIN_OBJ loc6;
GIN_OBJ loc7;
GIN_OBJ loc8;
GIN_OBJ loc9;
GIN_OBJ loc10;
GIN_OBJ loc11;
GIN_OBJ loc12;
GIN_OBJ loc13;
GIN_OBJ loc14;
GIN_OBJ loc15;
GIN_OBJ loc16;
GIN_OBJ loc17;
GIN_OBJ loc18;
GIN_OBJ loc19;
GIN_OBJ loc20;
GIN_OBJ loc21;
GIN_OBJ loc22;
GIN_OBJ loc23;
GIN_OBJ loc24;
GIN_OBJ loc25;
GIN_OBJ loc26;
GIN_OBJ loc27;
GIN_OBJ loc28;
GIN_OBJ loc29;
GIN_OBJ loc30;
GIN_OBJ loc31;
GIN_OBJ loc32;
GIN_OBJ loc33;
GIN_OBJ loc34;
GIN_OBJ loc35;
GIN_OBJ loc36;
GIN_OBJ loc37;
GIN_OBJ loc38;
GIN_OBJ loc39;
GIN_OBJ loc40;
GIN_OBJ loc41;
GIN_OBJ loc42;
GIN_OBJ loc43;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
GIN_OBJ tmp7;
GIN_OBJ tmp8;
GIN_OBJ tmp9;
GIN_OBJ tmp10;
GIN_OBJ tmp11;
GIN_OBJ tmp12;
GIN_OBJ tmp13;
GIN_OBJ tmp14;
GIN_OBJ tmp15;
GIN_OBJ tmp16;
} Frame___read;

#define ALLOCATE_FRAME___read(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___read));
#define DEALLOCATE_FRAME___read(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___state_045push;

#define ALLOCATE_FRAME___state_045push(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___state_045push));
#define DEALLOCATE_FRAME___state_045push(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ tmp0;
} Frame___state_045top;

#define ALLOCATE_FRAME___state_045top(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___state_045top));
#define DEALLOCATE_FRAME___state_045top(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ tmp0;
} Frame___state_045pop;

#define ALLOCATE_FRAME___state_045pop(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___state_045pop));
#define DEALLOCATE_FRAME___state_045pop(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___begin_045group_063;

#define ALLOCATE_FRAME___begin_045group_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___begin_045group_063));
#define DEALLOCATE_FRAME___begin_045group_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ loc0;
GIN_OBJ tmp0;
} Frame___paren_045balanced;

#define ALLOCATE_FRAME___paren_045balanced(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___paren_045balanced));
#define DEALLOCATE_FRAME___paren_045balanced(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___paren_045balanced_050;

#define ALLOCATE_FRAME___paren_045balanced_050(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___paren_045balanced_050));
#define DEALLOCATE_FRAME___paren_045balanced_050(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ loc0;
GIN_OBJ tmp0;
} Frame___paren_045add;

#define ALLOCATE_FRAME___paren_045add(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___paren_045add));
#define DEALLOCATE_FRAME___paren_045add(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___add_045paren_050;

#define ALLOCATE_FRAME___add_045paren_050(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___add_045paren_050));
#define DEALLOCATE_FRAME___add_045paren_050(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ loc0;
GIN_OBJ tmp0;
} Frame___paren_045remove;

#define ALLOCATE_FRAME___paren_045remove(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___paren_045remove));
#define DEALLOCATE_FRAME___paren_045remove(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___remove_045paren_050;

#define ALLOCATE_FRAME___remove_045paren_050(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___remove_045paren_050));
#define DEALLOCATE_FRAME___remove_045paren_050(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___tree_045add;

#define ALLOCATE_FRAME___tree_045add(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___tree_045add));
#define DEALLOCATE_FRAME___tree_045add(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___tree_045push;

#define ALLOCATE_FRAME___tree_045push(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___tree_045push));
#define DEALLOCATE_FRAME___tree_045push(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___tree_045pop;

#define ALLOCATE_FRAME___tree_045pop(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___tree_045pop));
#define DEALLOCATE_FRAME___tree_045pop(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ tmp0;
} Frame___tree_045unpop;

#define ALLOCATE_FRAME___tree_045unpop(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___tree_045unpop));
#define DEALLOCATE_FRAME___tree_045unpop(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ tmp0;
} Frame___tree_045set_045begin;

#define ALLOCATE_FRAME___tree_045set_045begin(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___tree_045set_045begin));
#define DEALLOCATE_FRAME___tree_045set_045begin(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___tree_045sibling_045count;

#define ALLOCATE_FRAME___tree_045sibling_045count(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___tree_045sibling_045count));
#define DEALLOCATE_FRAME___tree_045sibling_045count(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___escape_045char;

#define ALLOCATE_FRAME___escape_045char(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___escape_045char));
#define DEALLOCATE_FRAME___escape_045char(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
} Frame___dq_045escape;

#define ALLOCATE_FRAME___dq_045escape(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___dq_045escape));
#define DEALLOCATE_FRAME___dq_045escape(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___sq_045escape;

#define ALLOCATE_FRAME___sq_045escape(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___sq_045escape));
#define DEALLOCATE_FRAME___sq_045escape(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
} Frame___flatten_045functions;

#define ALLOCATE_FRAME___flatten_045functions(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___flatten_045functions));
#define DEALLOCATE_FRAME___flatten_045functions(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ loc4;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
GIN_OBJ tmp7;
GIN_OBJ tmp8;
GIN_OBJ tmp9;
} Frame___discover_045local_045variables;

#define ALLOCATE_FRAME___discover_045local_045variables(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___discover_045local_045variables));
#define DEALLOCATE_FRAME___discover_045local_045variables(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ arg2;
GIN_OBJ arg3;
GIN_OBJ arg4;
GIN_OBJ arg5;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
GIN_OBJ tmp7;
} Frame___add_045local_045variable;

#define ALLOCATE_FRAME___add_045local_045variable(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___add_045local_045variable));
#define DEALLOCATE_FRAME___add_045local_045variable(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
} Frame___search;

#define ALLOCATE_FRAME___search(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___search));
#define DEALLOCATE_FRAME___search(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___name_045_062c_045name;

#define ALLOCATE_FRAME___name_045_062c_045name(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___name_045_062c_045name));
#define DEALLOCATE_FRAME___name_045_062c_045name(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___p;

#define ALLOCATE_FRAME___p(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___p));
#define DEALLOCATE_FRAME___p(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ loc4;
GIN_OBJ loc5;
GIN_OBJ loc6;
GIN_OBJ loc7;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
} Frame___function_045prototype_045expansion;

#define ALLOCATE_FRAME___function_045prototype_045expansion(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___function_045prototype_045expansion));
#define DEALLOCATE_FRAME___function_045prototype_045expansion(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___function_045definition_045expansion;

#define ALLOCATE_FRAME___function_045definition_045expansion(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___function_045definition_045expansion));
#define DEALLOCATE_FRAME___function_045definition_045expansion(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame____060term_062_058_058register_045class_045symbol_063;

#define ALLOCATE_FRAME____060term_062_058_058register_045class_045symbol_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060term_062_058_058register_045class_045symbol_063));
#define DEALLOCATE_FRAME____060term_062_058_058register_045class_045symbol_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame____060list_062_045remove;

#define ALLOCATE_FRAME____060list_062_045remove(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060list_062_045remove));
#define DEALLOCATE_FRAME____060list_062_045remove(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ loc4;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
GIN_OBJ tmp7;
GIN_OBJ tmp8;
} Frame___lexical_045path;

#define ALLOCATE_FRAME___lexical_045path(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___lexical_045path));
#define DEALLOCATE_FRAME___lexical_045path(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
GIN_OBJ tmp7;
GIN_OBJ tmp8;
GIN_OBJ tmp9;
} Frame___lexical_045path_045i;

#define ALLOCATE_FRAME___lexical_045path_045i(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___lexical_045path_045i));
#define DEALLOCATE_FRAME___lexical_045path_045i(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ loc4;
GIN_OBJ loc5;
GIN_OBJ loc6;
GIN_OBJ loc7;
GIN_OBJ loc8;
GIN_OBJ loc9;
GIN_OBJ loc10;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
GIN_OBJ tmp7;
GIN_OBJ tmp8;
} Frame___function_045expansion;

#define ALLOCATE_FRAME___function_045expansion(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___function_045expansion));
#define DEALLOCATE_FRAME___function_045expansion(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___next_045tmp;

#define ALLOCATE_FRAME___next_045tmp(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___next_045tmp));
#define DEALLOCATE_FRAME___next_045tmp(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ tmp0;
} Frame___previous_045tmp;

#define ALLOCATE_FRAME___previous_045tmp(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___previous_045tmp));
#define DEALLOCATE_FRAME___previous_045tmp(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
} Frame___flatten_045term;

#define ALLOCATE_FRAME___flatten_045term(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___flatten_045term));
#define DEALLOCATE_FRAME___flatten_045term(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
} Frame___flatten_045set;

#define ALLOCATE_FRAME___flatten_045set(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___flatten_045set));
#define DEALLOCATE_FRAME___flatten_045set(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ loc4;
GIN_OBJ loc5;
GIN_OBJ loc6;
GIN_OBJ loc7;
GIN_OBJ loc8;
GIN_OBJ loc9;
GIN_OBJ loc10;
GIN_OBJ loc11;
GIN_OBJ loc12;
GIN_OBJ loc13;
GIN_OBJ loc14;
GIN_OBJ loc15;
GIN_OBJ loc16;
GIN_OBJ loc17;
GIN_OBJ loc18;
GIN_OBJ loc19;
GIN_OBJ loc20;
GIN_OBJ loc21;
GIN_OBJ loc22;
GIN_OBJ loc23;
GIN_OBJ loc24;
GIN_OBJ loc25;
GIN_OBJ loc26;
GIN_OBJ loc27;
GIN_OBJ loc28;
GIN_OBJ loc29;
GIN_OBJ loc30;
GIN_OBJ loc31;
GIN_OBJ loc32;
GIN_OBJ loc33;
GIN_OBJ loc34;
GIN_OBJ loc35;
GIN_OBJ loc36;
GIN_OBJ loc37;
GIN_OBJ loc38;
GIN_OBJ loc39;
GIN_OBJ loc40;
GIN_OBJ loc41;
GIN_OBJ loc42;
GIN_OBJ loc43;
GIN_OBJ loc44;
GIN_OBJ loc45;
GIN_OBJ loc46;
GIN_OBJ loc47;
GIN_OBJ loc48;
GIN_OBJ loc49;
GIN_OBJ loc50;
GIN_OBJ loc51;
GIN_OBJ loc52;
GIN_OBJ loc53;
GIN_OBJ loc54;
GIN_OBJ loc55;
GIN_OBJ loc56;
GIN_OBJ loc57;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
GIN_OBJ tmp7;
GIN_OBJ tmp8;
GIN_OBJ tmp9;
GIN_OBJ tmp10;
GIN_OBJ tmp11;
GIN_OBJ tmp12;
GIN_OBJ tmp13;
GIN_OBJ tmp14;
GIN_OBJ tmp15;
GIN_OBJ tmp16;
} Frame___flatten;

#define ALLOCATE_FRAME___flatten(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___flatten));
#define DEALLOCATE_FRAME___flatten(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___test;

#define ALLOCATE_FRAME___test(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___test));
#define DEALLOCATE_FRAME___test(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___Residual_063;

#define ALLOCATE_FRAME___Residual_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Residual_063));
#define DEALLOCATE_FRAME___Residual_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
GIN_OBJ tmp7;
} Frame___find_045named_045parameter_048;

#define ALLOCATE_FRAME___find_045named_045parameter_048(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___find_045named_045parameter_048));
#define DEALLOCATE_FRAME___find_045named_045parameter_048(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___remove_045named_045parameter;

#define ALLOCATE_FRAME___remove_045named_045parameter(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___remove_045named_045parameter));
#define DEALLOCATE_FRAME___remove_045named_045parameter(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ tmp0;
} Frame___delayed_045previous_045tmp;

#define ALLOCATE_FRAME___delayed_045previous_045tmp(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___delayed_045previous_045tmp));
#define DEALLOCATE_FRAME___delayed_045previous_045tmp(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___string_045n;

#define ALLOCATE_FRAME___string_045n(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___string_045n));
#define DEALLOCATE_FRAME___string_045n(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
} Frame___discover_045quoted_045symbols;

#define ALLOCATE_FRAME___discover_045quoted_045symbols(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___discover_045quoted_045symbols));
#define DEALLOCATE_FRAME___discover_045quoted_045symbols(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___print_045version;

#define ALLOCATE_FRAME___print_045version(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___print_045version));
#define DEALLOCATE_FRAME___print_045version(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
GIN_OBJ tmp7;
} Frame___process_045arguments;

#define ALLOCATE_FRAME___process_045arguments(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___process_045arguments));
#define DEALLOCATE_FRAME___process_045arguments(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___cairo_045create;

#define ALLOCATE_FRAME___cairo_045create(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___cairo_045create));
#define DEALLOCATE_FRAME___cairo_045create(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___cairo_045destroy;

#define ALLOCATE_FRAME___cairo_045destroy(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___cairo_045destroy));
#define DEALLOCATE_FRAME___cairo_045destroy(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___cairo_045image_045surface_045create;

#define ALLOCATE_FRAME___cairo_045image_045surface_045create(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___cairo_045image_045surface_045create));
#define DEALLOCATE_FRAME___cairo_045image_045surface_045create(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ arg2;
GIN_OBJ tmp0;
} Frame___cairo_045pdf_045surface_045create;

#define ALLOCATE_FRAME___cairo_045pdf_045surface_045create(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___cairo_045pdf_045surface_045create));
#define DEALLOCATE_FRAME___cairo_045pdf_045surface_045create(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___cairo_045image_045surface_045create_045from_045png;

#define ALLOCATE_FRAME___cairo_045image_045surface_045create_045from_045png(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___cairo_045image_045surface_045create_045from_045png));
#define DEALLOCATE_FRAME___cairo_045image_045surface_045create_045from_045png(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___cairo_045win_051_050_045surface_045create;

#define ALLOCATE_FRAME___cairo_045win_051_050_045surface_045create(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___cairo_045win_051_050_045surface_045create));
#define DEALLOCATE_FRAME___cairo_045win_051_050_045surface_045create(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ arg2;
GIN_OBJ arg3;
GIN_OBJ arg4;
GIN_OBJ tmp0;
} Frame___cairo_045xlib_045surface_045create;

#define ALLOCATE_FRAME___cairo_045xlib_045surface_045create(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___cairo_045xlib_045surface_045create));
#define DEALLOCATE_FRAME___cairo_045xlib_045surface_045create(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___cairo_045surface_045destroy;

#define ALLOCATE_FRAME___cairo_045surface_045destroy(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___cairo_045surface_045destroy));
#define DEALLOCATE_FRAME___cairo_045surface_045destroy(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame____060cairo_062_045image_045surface_045get_045width;

#define ALLOCATE_FRAME____060cairo_062_045image_045surface_045get_045width(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060cairo_062_045image_045surface_045get_045width));
#define DEALLOCATE_FRAME____060cairo_062_045image_045surface_045get_045width(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame____060cairo_062_045image_045surface_045get_045height;

#define ALLOCATE_FRAME____060cairo_062_045image_045surface_045get_045height(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060cairo_062_045image_045surface_045get_045height));
#define DEALLOCATE_FRAME____060cairo_062_045image_045surface_045get_045height(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ arg2;
GIN_OBJ tmp0;
} Frame____060cairo_062_045image_045surface_045fallback_045resolution;

#define ALLOCATE_FRAME____060cairo_062_045image_045surface_045fallback_045resolution(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060cairo_062_045image_045surface_045fallback_045resolution));
#define DEALLOCATE_FRAME____060cairo_062_045image_045surface_045fallback_045resolution(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ tmp0;
} Frame____060cairo_062_045user_045to_045device_045x;

#define ALLOCATE_FRAME____060cairo_062_045user_045to_045device_045x(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060cairo_062_045user_045to_045device_045x));
#define DEALLOCATE_FRAME____060cairo_062_045user_045to_045device_045x(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ tmp0;
} Frame____060cairo_062_045user_045to_045device_045y;

#define ALLOCATE_FRAME____060cairo_062_045user_045to_045device_045y(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060cairo_062_045user_045to_045device_045y));
#define DEALLOCATE_FRAME____060cairo_062_045user_045to_045device_045y(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ arg2;
GIN_OBJ tmp0;
} Frame____060cairo_062_045translate;

#define ALLOCATE_FRAME____060cairo_062_045translate(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060cairo_062_045translate));
#define DEALLOCATE_FRAME____060cairo_062_045translate(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ arg2;
GIN_OBJ tmp0;
} Frame____060cairo_062_045scale;

#define ALLOCATE_FRAME____060cairo_062_045scale(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060cairo_062_045scale));
#define DEALLOCATE_FRAME____060cairo_062_045scale(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ arg2;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___cairo_045use_045cartesian_045coordinate_045system;

#define ALLOCATE_FRAME___cairo_045use_045cartesian_045coordinate_045system(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___cairo_045use_045cartesian_045coordinate_045system));
#define DEALLOCATE_FRAME___cairo_045use_045cartesian_045coordinate_045system(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame____060cairo_062_045set_045line_045width;

#define ALLOCATE_FRAME____060cairo_062_045set_045line_045width(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060cairo_062_045set_045line_045width));
#define DEALLOCATE_FRAME____060cairo_062_045set_045line_045width(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ arg2;
GIN_OBJ arg3;
GIN_OBJ tmp0;
} Frame____060cairo_062_045set_045source_045rgb;

#define ALLOCATE_FRAME____060cairo_062_045set_045source_045rgb(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060cairo_062_045set_045source_045rgb));
#define DEALLOCATE_FRAME____060cairo_062_045set_045source_045rgb(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ arg2;
GIN_OBJ arg3;
GIN_OBJ tmp0;
} Frame____060cairo_062_045set_045source_045surface;

#define ALLOCATE_FRAME____060cairo_062_045set_045source_045surface(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060cairo_062_045set_045source_045surface));
#define DEALLOCATE_FRAME____060cairo_062_045set_045source_045surface(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ arg2;
GIN_OBJ arg3;
GIN_OBJ arg4;
GIN_OBJ tmp0;
} Frame____060cairo_062_045rectangle;

#define ALLOCATE_FRAME____060cairo_062_045rectangle(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060cairo_062_045rectangle));
#define DEALLOCATE_FRAME____060cairo_062_045rectangle(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame____060cairo_062_045stroke;

#define ALLOCATE_FRAME____060cairo_062_045stroke(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060cairo_062_045stroke));
#define DEALLOCATE_FRAME____060cairo_062_045stroke(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame____060cairo_062_045surface_045write_045to_045png;

#define ALLOCATE_FRAME____060cairo_062_045surface_045write_045to_045png(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060cairo_062_045surface_045write_045to_045png));
#define DEALLOCATE_FRAME____060cairo_062_045surface_045write_045to_045png(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame____060cairo_062_045paint;

#define ALLOCATE_FRAME____060cairo_062_045paint(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060cairo_062_045paint));
#define DEALLOCATE_FRAME____060cairo_062_045paint(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ arg2;
GIN_OBJ tmp0;
} Frame____060cairo_062_045move_045to;

#define ALLOCATE_FRAME____060cairo_062_045move_045to(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060cairo_062_045move_045to));
#define DEALLOCATE_FRAME____060cairo_062_045move_045to(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ arg2;
GIN_OBJ tmp0;
} Frame____060cairo_062_045line_045to;

#define ALLOCATE_FRAME____060cairo_062_045line_045to(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060cairo_062_045line_045to));
#define DEALLOCATE_FRAME____060cairo_062_045line_045to(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame____060cairo_062_045show_045page;

#define ALLOCATE_FRAME____060cairo_062_045show_045page(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame____060cairo_062_045show_045page));
#define DEALLOCATE_FRAME____060cairo_062_045show_045page(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___Cairo_058_058set_045black;

#define ALLOCATE_FRAME___Cairo_058_058set_045black(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Cairo_058_058set_045black));
#define DEALLOCATE_FRAME___Cairo_058_058set_045black(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___Cairo_058_058set_045white;

#define ALLOCATE_FRAME___Cairo_058_058set_045white(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Cairo_058_058set_045white));
#define DEALLOCATE_FRAME___Cairo_058_058set_045white(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___Cairo_058_058set_045red;

#define ALLOCATE_FRAME___Cairo_058_058set_045red(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Cairo_058_058set_045red));
#define DEALLOCATE_FRAME___Cairo_058_058set_045red(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___Cairo_058_058set_045green;

#define ALLOCATE_FRAME___Cairo_058_058set_045green(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Cairo_058_058set_045green));
#define DEALLOCATE_FRAME___Cairo_058_058set_045green(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___Cairo_058_058set_045blue;

#define ALLOCATE_FRAME___Cairo_058_058set_045blue(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Cairo_058_058set_045blue));
#define DEALLOCATE_FRAME___Cairo_058_058set_045blue(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Pango_058_058context_045list_045families;

#define ALLOCATE_FRAME___Pango_058_058context_045list_045families(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Pango_058_058context_045list_045families));
#define DEALLOCATE_FRAME___Pango_058_058context_045list_045families(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ tmp0;
} Frame___Pango_058_058font_045description_045new;

#define ALLOCATE_FRAME___Pango_058_058font_045description_045new(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Pango_058_058font_045description_045new));
#define DEALLOCATE_FRAME___Pango_058_058font_045description_045new(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Pango_058_058font_045description_045from_045string;

#define ALLOCATE_FRAME___Pango_058_058font_045description_045from_045string(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Pango_058_058font_045description_045from_045string));
#define DEALLOCATE_FRAME___Pango_058_058font_045description_045from_045string(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Pango_058_058font_045description_045set_045family;

#define ALLOCATE_FRAME___Pango_058_058font_045description_045set_045family(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Pango_058_058font_045description_045set_045family));
#define DEALLOCATE_FRAME___Pango_058_058font_045description_045set_045family(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Pango_058_058font_045description_045set_045weight;

#define ALLOCATE_FRAME___Pango_058_058font_045description_045set_045weight(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Pango_058_058font_045description_045set_045weight));
#define DEALLOCATE_FRAME___Pango_058_058font_045description_045set_045weight(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Pango_058_058font_045description_045set_045absolute_045size;

#define ALLOCATE_FRAME___Pango_058_058font_045description_045set_045absolute_045size(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Pango_058_058font_045description_045set_045absolute_045size));
#define DEALLOCATE_FRAME___Pango_058_058font_045description_045set_045absolute_045size(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Pango_058_058font_045description_045free;

#define ALLOCATE_FRAME___Pango_058_058font_045description_045free(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Pango_058_058font_045description_045free));
#define DEALLOCATE_FRAME___Pango_058_058font_045description_045free(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Pango_058_058cairo_045create_045layout;

#define ALLOCATE_FRAME___Pango_058_058cairo_045create_045layout(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Pango_058_058cairo_045create_045layout));
#define DEALLOCATE_FRAME___Pango_058_058cairo_045create_045layout(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Pango_058_058cairo_045show_045layout;

#define ALLOCATE_FRAME___Pango_058_058cairo_045show_045layout(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Pango_058_058cairo_045show_045layout));
#define DEALLOCATE_FRAME___Pango_058_058cairo_045show_045layout(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Pango_058_058layout_045get_045context;

#define ALLOCATE_FRAME___Pango_058_058layout_045get_045context(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Pango_058_058layout_045get_045context));
#define DEALLOCATE_FRAME___Pango_058_058layout_045get_045context(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ arg2;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___Pango_058_058layout_045set_045text;

#define ALLOCATE_FRAME___Pango_058_058layout_045set_045text(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Pango_058_058layout_045set_045text));
#define DEALLOCATE_FRAME___Pango_058_058layout_045set_045text(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ arg2;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___Pango_058_058layout_045set_045markup;

#define ALLOCATE_FRAME___Pango_058_058layout_045set_045markup(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Pango_058_058layout_045set_045markup));
#define DEALLOCATE_FRAME___Pango_058_058layout_045set_045markup(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Pango_058_058layout_045set_045font_045description;

#define ALLOCATE_FRAME___Pango_058_058layout_045set_045font_045description(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Pango_058_058layout_045set_045font_045description));
#define DEALLOCATE_FRAME___Pango_058_058layout_045set_045font_045description(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Pango_058_058layout_045set_045width;

#define ALLOCATE_FRAME___Pango_058_058layout_045set_045width(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Pango_058_058layout_045set_045width));
#define DEALLOCATE_FRAME___Pango_058_058layout_045set_045width(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Pango_058_058layout_045get_045width;

#define ALLOCATE_FRAME___Pango_058_058layout_045get_045width(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Pango_058_058layout_045get_045width));
#define DEALLOCATE_FRAME___Pango_058_058layout_045get_045width(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Pango_058_058layout_045set_045height;

#define ALLOCATE_FRAME___Pango_058_058layout_045set_045height(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Pango_058_058layout_045set_045height));
#define DEALLOCATE_FRAME___Pango_058_058layout_045set_045height(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Pango_058_058layout_045get_045height;

#define ALLOCATE_FRAME___Pango_058_058layout_045get_045height(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Pango_058_058layout_045get_045height));
#define DEALLOCATE_FRAME___Pango_058_058layout_045get_045height(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ tmp0;
} Frame___Pango_058_058layout_045get_045extents_045logical_045height;

#define ALLOCATE_FRAME___Pango_058_058layout_045get_045extents_045logical_045height(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Pango_058_058layout_045get_045extents_045logical_045height));
#define DEALLOCATE_FRAME___Pango_058_058layout_045get_045extents_045logical_045height(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Pango_058_058layout_045index_045to_045y;

#define ALLOCATE_FRAME___Pango_058_058layout_045index_045to_045y(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Pango_058_058layout_045index_045to_045y));
#define DEALLOCATE_FRAME___Pango_058_058layout_045index_045to_045y(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Pango_058_058layout_045set_045indent;

#define ALLOCATE_FRAME___Pango_058_058layout_045set_045indent(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Pango_058_058layout_045set_045indent));
#define DEALLOCATE_FRAME___Pango_058_058layout_045set_045indent(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___Pango_058_058layout_045get_045indent;

#define ALLOCATE_FRAME___Pango_058_058layout_045get_045indent(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Pango_058_058layout_045get_045indent));
#define DEALLOCATE_FRAME___Pango_058_058layout_045get_045indent(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Pango_058_058layout_045set_045spacing;

#define ALLOCATE_FRAME___Pango_058_058layout_045set_045spacing(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Pango_058_058layout_045set_045spacing));
#define DEALLOCATE_FRAME___Pango_058_058layout_045set_045spacing(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Pango_058_058layout_045set_045justify;

#define ALLOCATE_FRAME___Pango_058_058layout_045set_045justify(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Pango_058_058layout_045set_045justify));
#define DEALLOCATE_FRAME___Pango_058_058layout_045set_045justify(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
} Frame___Pango_058_058layout_045set_045alignment;

#define ALLOCATE_FRAME___Pango_058_058layout_045set_045alignment(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Pango_058_058layout_045set_045alignment));
#define DEALLOCATE_FRAME___Pango_058_058layout_045set_045alignment(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___g_045object_045unref;

#define ALLOCATE_FRAME___g_045object_045unref(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___g_045object_045unref));
#define DEALLOCATE_FRAME___g_045object_045unref(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ tmp0;
} Frame___PDF_058_058make_045document;

#define ALLOCATE_FRAME___PDF_058_058make_045document(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___PDF_058_058make_045document));
#define DEALLOCATE_FRAME___PDF_058_058make_045document(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___make_045us_045letter;

#define ALLOCATE_FRAME___make_045us_045letter(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___make_045us_045letter));
#define DEALLOCATE_FRAME___make_045us_045letter(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ arg2;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___PDF_058_058make_045font;

#define ALLOCATE_FRAME___PDF_058_058make_045font(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___PDF_058_058make_045font));
#define DEALLOCATE_FRAME___PDF_058_058make_045font(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___family_045_062pango;

#define ALLOCATE_FRAME___family_045_062pango(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___family_045_062pango));
#define DEALLOCATE_FRAME___family_045_062pango(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___weight_045_062pango;

#define ALLOCATE_FRAME___weight_045_062pango(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___weight_045_062pango));
#define DEALLOCATE_FRAME___weight_045_062pango(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___size_045_062pango;

#define ALLOCATE_FRAME___size_045_062pango(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___size_045_062pango));
#define DEALLOCATE_FRAME___size_045_062pango(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___PDF_058_058make_045font_045from_045string;

#define ALLOCATE_FRAME___PDF_058_058make_045font_045from_045string(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___PDF_058_058make_045font_045from_045string));
#define DEALLOCATE_FRAME___PDF_058_058make_045font_045from_045string(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___PDF_058_058make_045paragraph;

#define ALLOCATE_FRAME___PDF_058_058make_045paragraph(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___PDF_058_058make_045paragraph));
#define DEALLOCATE_FRAME___PDF_058_058make_045paragraph(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___printable_045boundry_045bottom;

#define ALLOCATE_FRAME___printable_045boundry_045bottom(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___printable_045boundry_045bottom));
#define DEALLOCATE_FRAME___printable_045boundry_045bottom(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___printable_045width;

#define ALLOCATE_FRAME___printable_045width(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___printable_045width));
#define DEALLOCATE_FRAME___printable_045width(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ loc4;
GIN_OBJ loc5;
GIN_OBJ loc6;
GIN_OBJ loc7;
GIN_OBJ loc8;
GIN_OBJ loc9;
GIN_OBJ loc10;
GIN_OBJ loc11;
GIN_OBJ loc12;
GIN_OBJ loc13;
GIN_OBJ loc14;
GIN_OBJ loc15;
GIN_OBJ loc16;
GIN_OBJ loc17;
GIN_OBJ loc18;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___PDF_058_058add_045paragraph;

#define ALLOCATE_FRAME___PDF_058_058add_045paragraph(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___PDF_058_058add_045paragraph));
#define DEALLOCATE_FRAME___PDF_058_058add_045paragraph(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ loc4;
GIN_OBJ loc5;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___make_045layout;

#define ALLOCATE_FRAME___make_045layout(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___make_045layout));
#define DEALLOCATE_FRAME___make_045layout(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___doc_045width;

#define ALLOCATE_FRAME___doc_045width(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___doc_045width));
#define DEALLOCATE_FRAME___doc_045width(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___doc_045left_045margin;

#define ALLOCATE_FRAME___doc_045left_045margin(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___doc_045left_045margin));
#define DEALLOCATE_FRAME___doc_045left_045margin(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___doc_045right_045margin;

#define ALLOCATE_FRAME___doc_045right_045margin(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___doc_045right_045margin));
#define DEALLOCATE_FRAME___doc_045right_045margin(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___alignment_045_062pango;

#define ALLOCATE_FRAME___alignment_045_062pango(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___alignment_045_062pango));
#define DEALLOCATE_FRAME___alignment_045_062pango(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___new_045cursor_045y;

#define ALLOCATE_FRAME___new_045cursor_045y(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___new_045cursor_045y));
#define DEALLOCATE_FRAME___new_045cursor_045y(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___printable_045height;

#define ALLOCATE_FRAME___printable_045height(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___printable_045height));
#define DEALLOCATE_FRAME___printable_045height(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ tmp0;
} Frame___new_045page;

#define ALLOCATE_FRAME___new_045page(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___new_045page));
#define DEALLOCATE_FRAME___new_045page(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___relative_045position_045of_045break;

#define ALLOCATE_FRAME___relative_045position_045of_045break(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___relative_045position_045of_045break));
#define DEALLOCATE_FRAME___relative_045position_045of_045break(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___last_045logical_045break_045not_045exceeding_045printable_045boundry_045bottom;

#define ALLOCATE_FRAME___last_045logical_045break_045not_045exceeding_045printable_045boundry_045bottom(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___last_045logical_045break_045not_045exceeding_045printable_045boundry_045bottom));
#define DEALLOCATE_FRAME___last_045logical_045break_045not_045exceeding_045printable_045boundry_045bottom(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
GIN_OBJ tmp7;
} Frame___logical_045breaks;

#define ALLOCATE_FRAME___logical_045breaks(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___logical_045breaks));
#define DEALLOCATE_FRAME___logical_045breaks(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___end_045of_045paragraph;

#define ALLOCATE_FRAME___end_045of_045paragraph(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___end_045of_045paragraph));
#define DEALLOCATE_FRAME___end_045of_045paragraph(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ arg2;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___slice;

#define ALLOCATE_FRAME___slice(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___slice));
#define DEALLOCATE_FRAME___slice(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ tmp0;
} Frame___set_045color;

#define ALLOCATE_FRAME___set_045color(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___set_045color));
#define DEALLOCATE_FRAME___set_045color(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ loc4;
GIN_OBJ loc5;
GIN_OBJ loc6;
GIN_OBJ loc7;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___PDF_058_058add_045image;

#define ALLOCATE_FRAME___PDF_058_058add_045image(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___PDF_058_058add_045image));
#define DEALLOCATE_FRAME___PDF_058_058add_045image(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ tmp0;
} Frame___add_045image_045new_045cursor_045y;

#define ALLOCATE_FRAME___add_045image_045new_045cursor_045y(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___add_045image_045new_045cursor_045y));
#define DEALLOCATE_FRAME___add_045image_045new_045cursor_045y(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___add_045image_045new_045page;

#define ALLOCATE_FRAME___add_045image_045new_045page(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___add_045image_045new_045page));
#define DEALLOCATE_FRAME___add_045image_045new_045page(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___PDF_058_058copy_045paragraph_045attributes;

#define ALLOCATE_FRAME___PDF_058_058copy_045paragraph_045attributes(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___PDF_058_058copy_045paragraph_045attributes));
#define DEALLOCATE_FRAME___PDF_058_058copy_045paragraph_045attributes(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___PDF_058_058close;

#define ALLOCATE_FRAME___PDF_058_058close(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___PDF_058_058close));
#define DEALLOCATE_FRAME___PDF_058_058close(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___lt;

#define ALLOCATE_FRAME___lt(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___lt));
#define DEALLOCATE_FRAME___lt(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___gt;

#define ALLOCATE_FRAME___gt(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___gt));
#define DEALLOCATE_FRAME___gt(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ arg1;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___Literate_058_058weave_045pdf;

#define ALLOCATE_FRAME___Literate_058_058weave_045pdf(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Literate_058_058weave_045pdf));
#define DEALLOCATE_FRAME___Literate_058_058weave_045pdf(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ loc4;
GIN_OBJ loc5;
GIN_OBJ loc6;
GIN_OBJ loc7;
GIN_OBJ loc8;
GIN_OBJ loc9;
GIN_OBJ loc10;
GIN_OBJ loc11;
GIN_OBJ loc12;
GIN_OBJ loc13;
GIN_OBJ loc14;
GIN_OBJ loc15;
GIN_OBJ loc16;
GIN_OBJ loc17;
GIN_OBJ loc18;
GIN_OBJ loc19;
GIN_OBJ loc20;
GIN_OBJ loc21;
GIN_OBJ loc22;
GIN_OBJ loc23;
GIN_OBJ loc24;
GIN_OBJ loc25;
GIN_OBJ loc26;
GIN_OBJ loc27;
GIN_OBJ loc28;
GIN_OBJ loc29;
GIN_OBJ loc30;
GIN_OBJ loc31;
GIN_OBJ loc32;
GIN_OBJ loc33;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
GIN_OBJ tmp7;
GIN_OBJ tmp8;
} Frame___weave_045tree;

#define ALLOCATE_FRAME___weave_045tree(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___weave_045tree));
#define DEALLOCATE_FRAME___weave_045tree(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___title_063;

#define ALLOCATE_FRAME___title_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___title_063));
#define DEALLOCATE_FRAME___title_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___section_063;

#define ALLOCATE_FRAME___section_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___section_063));
#define DEALLOCATE_FRAME___section_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___doc_063;

#define ALLOCATE_FRAME___doc_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___doc_063));
#define DEALLOCATE_FRAME___doc_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___Lit_058_058chunk_063;

#define ALLOCATE_FRAME___Lit_058_058chunk_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___Lit_058_058chunk_063));
#define DEALLOCATE_FRAME___Lit_058_058chunk_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___code_063;

#define ALLOCATE_FRAME___code_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___code_063));
#define DEALLOCATE_FRAME___code_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___image_063;

#define ALLOCATE_FRAME___image_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___image_063));
#define DEALLOCATE_FRAME___image_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___title_045_062string;

#define ALLOCATE_FRAME___title_045_062string(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___title_045_062string));
#define DEALLOCATE_FRAME___title_045_062string(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___section_045_062string;

#define ALLOCATE_FRAME___section_045_062string(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___section_045_062string));
#define DEALLOCATE_FRAME___section_045_062string(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ loc4;
GIN_OBJ loc5;
GIN_OBJ loc6;
GIN_OBJ loc7;
GIN_OBJ loc8;
GIN_OBJ loc9;
GIN_OBJ loc10;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
GIN_OBJ tmp7;
} Frame___doc_045_062string;

#define ALLOCATE_FRAME___doc_045_062string(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___doc_045_062string));
#define DEALLOCATE_FRAME___doc_045_062string(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
} Frame___string_045append_063;

#define ALLOCATE_FRAME___string_045append_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___string_045append_063));
#define DEALLOCATE_FRAME___string_045append_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___math_063;

#define ALLOCATE_FRAME___math_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___math_063));
#define DEALLOCATE_FRAME___math_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___cite_063;

#define ALLOCATE_FRAME___cite_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___cite_063));
#define DEALLOCATE_FRAME___cite_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
GIN_OBJ tmp7;
} Frame___fmt_045doc;

#define ALLOCATE_FRAME___fmt_045doc(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___fmt_045doc));
#define DEALLOCATE_FRAME___fmt_045doc(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___nofmt;

#define ALLOCATE_FRAME___nofmt(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___nofmt));
#define DEALLOCATE_FRAME___nofmt(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___nocode;

#define ALLOCATE_FRAME___nocode(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___nocode));
#define DEALLOCATE_FRAME___nocode(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___nomath;

#define ALLOCATE_FRAME___nomath(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___nomath));
#define DEALLOCATE_FRAME___nomath(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___cite;

#define ALLOCATE_FRAME___cite(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___cite));
#define DEALLOCATE_FRAME___cite(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___chunk_045_062string;

#define ALLOCATE_FRAME___chunk_045_062string(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___chunk_045_062string));
#define DEALLOCATE_FRAME___chunk_045_062string(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___fmt_045chunk_045calls;

#define ALLOCATE_FRAME___fmt_045chunk_045calls(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___fmt_045chunk_045calls));
#define DEALLOCATE_FRAME___fmt_045chunk_045calls(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___fmt_045chunk_045call_063;

#define ALLOCATE_FRAME___fmt_045chunk_045call_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___fmt_045chunk_045call_063));
#define DEALLOCATE_FRAME___fmt_045chunk_045call_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ loc4;
GIN_OBJ loc5;
GIN_OBJ loc6;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
} Frame___fmt_045chunk_045call;

#define ALLOCATE_FRAME___fmt_045chunk_045call(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___fmt_045chunk_045call));
#define DEALLOCATE_FRAME___fmt_045chunk_045call(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
} Frame___escape;

#define ALLOCATE_FRAME___escape(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___escape));
#define DEALLOCATE_FRAME___escape(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___code_045_062string;

#define ALLOCATE_FRAME___code_045_062string(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___code_045_062string));
#define DEALLOCATE_FRAME___code_045_062string(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
} Frame___image_045_062filename;

#define ALLOCATE_FRAME___image_045_062filename(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___image_045_062filename));
#define DEALLOCATE_FRAME___image_045_062filename(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
GIN_OBJ tmp7;
GIN_OBJ tmp8;
} Frame___fmt_045math;

#define ALLOCATE_FRAME___fmt_045math(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___fmt_045math));
#define DEALLOCATE_FRAME___fmt_045math(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___math;

#define ALLOCATE_FRAME___math(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___math));
#define DEALLOCATE_FRAME___math(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___bibliography;

#define ALLOCATE_FRAME___bibliography(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___bibliography));
#define DEALLOCATE_FRAME___bibliography(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ loc3;
GIN_OBJ loc4;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___expand_045chunks;

#define ALLOCATE_FRAME___expand_045chunks(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___expand_045chunks));
#define DEALLOCATE_FRAME___expand_045chunks(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
} Frame___chunk_045name;

#define ALLOCATE_FRAME___chunk_045name(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___chunk_045name));
#define DEALLOCATE_FRAME___chunk_045name(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
} Frame___chunk_063;

#define ALLOCATE_FRAME___chunk_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___chunk_063));
#define DEALLOCATE_FRAME___chunk_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___discover_045chunks;

#define ALLOCATE_FRAME___discover_045chunks(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___discover_045chunks));
#define DEALLOCATE_FRAME___discover_045chunks(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___expand_045chunk_045calls;

#define ALLOCATE_FRAME___expand_045chunk_045calls(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___expand_045chunk_045calls));
#define DEALLOCATE_FRAME___expand_045chunk_045calls(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
} Frame___chunk_045call_063;

#define ALLOCATE_FRAME___chunk_045call_063(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___chunk_045call_063));
#define DEALLOCATE_FRAME___chunk_045call_063(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
GIN_OBJ tmp6;
} Frame___macro_045key;

#define ALLOCATE_FRAME___macro_045key(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___macro_045key));
#define DEALLOCATE_FRAME___macro_045key(t000) GIN_DEALLOCATE_FRAME(t000);

typedef struct {
Frame* next_frame;
Frame* previous_frame;
Frame* previous_lexical_frame;
GIN_OBJ return_address;
GIN_OBJ result;
GIN_OBJ arg0;
GIN_OBJ loc0;
GIN_OBJ loc1;
GIN_OBJ loc2;
GIN_OBJ tmp0;
GIN_OBJ tmp1;
GIN_OBJ tmp2;
GIN_OBJ tmp3;
GIN_OBJ tmp4;
GIN_OBJ tmp5;
} Frame___expand_045chunk_045call;

#define ALLOCATE_FRAME___expand_045chunk_045call(t000) GIN_ALLOCATE_FRAME(t000, Frame*, sizeof(Frame___expand_045chunk_045call));
#define DEALLOCATE_FRAME___expand_045chunk_045call(t000) GIN_DEALLOCATE_FRAME(t000);

