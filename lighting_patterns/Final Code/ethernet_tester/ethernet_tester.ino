#include "FastLED.h"
#include "Graph.hpp"


// IO/Hardware config
//--------------------------------------------------
#define NUM_PINS 1
// ALL THESE ARE FOR THE TOP ETHERNET JACK
#define DATA_PIN0 2 // Green wire
#define DATA_PIN1 4 // Blue wire
#define DATA_PIN2 6 // Green wire
#define DATA_PIN3 8 // Brown wire
#define CLOCK_PIN 13

#define SENSOR0 0

#define LED_TYPE WS2812
#define BRIGHTNESS 255
//--------------------------------------------------


// Crystals/LEDs config
//--------------------------------------------------
#define NUM_CRYSTALS 291
#define CRYSTALS_PER_PIN 17 // Total crystal designs
#define LEDS_PER_PIN 50 // Number of LEDs per strip
//--------------------------------------------------


CRGB leds[LEDS_PER_PIN * NUM_PINS];

uint16_t firstLED[NUM_CRYSTALS] = {0,5,10,13,16,21,27,33,40,45,48,54,58,67,71,75,79,85,88,94,100,107,111,115,122,129,133,138,144,152,158,165,172,176,182,186,190,194,198,202,206,211,215,219,223,228,236,245,250,254,260,263,267,271,275,282,287,292,298,304,307,313,318,325,333,338,345,352,356,362,367,372,377,383,389,392,395,398,402,407,414,420,429,432,434,439,447,451,455,459,462,465,469,473,482,488,491,495,504,510,515,521,529,533,536,542,550,555,562,566,572,578,585,590,595,602,607,610,615,622,630,633,637,641,647,654,658,666,675,681,688,692,696,699,706,713,716,724,730,734,740,743,746,752,755,761,765,776,787,797,807,810,816,824,829,836,840,846,852,859,864,869,876,881,884,889,896,904,907,911,915,921,928,932,940,949,955,962,966,970,973,980,987,990,998,1004,1008,1014,1017,1020,1026,1029,1033,1038,1043,1048,1054,1060,1063,1069,1075,1078,1081,1085,1090,1097,1103,1112,1115,1117,1122,1130,1134,1138,1142,1145,1148,1152,1156,1165,1171,1174,1178,1187,1193,1197,1202,1206,1210,1215,1220,1224,1228,1232,1236,1240,1244,1249,1257,1266,1271,1275,1281,1284,1288,1292,1296,1303,1308,1313,1319,1325,1328,1334,1339,1346,1354,1359,1366,1373,1382,1387,1390,1393,1397,1403,1409,1416,1421,1424,1430,1434,1443,1447,1451,1455,1461,1464,1470,1476,1483,1487,1491,1498,1505,1509,1514,1520,1528,1534,1541};
uint16_t lastLED[NUM_CRYSTALS] = {4,9,12,15,20,26,32,39,44,47,53,57,66,70,74,78,84,87,93,99,106,110,114,121,128,132,137,143,151,157,164,171,175,181,185,189,193,197,201,205,210,214,218,222,227,235,244,249,253,259,262,266,270,274,281,286,291,297,303,306,312,317,324,332,337,344,351,355,361,366,371,376,382,388,391,394,397,401,406,413,419,428,431,433,438,446,450,454,458,461,464,468,472,481,487,490,494,503,509,514,520,528,532,535,541,549,554,561,565,571,577,584,589,594,601,606,609,614,621,629,632,636,640,646,653,657,665,674,680,687,691,695,698,705,712,715,723,729,733,739,742,745,751,754,760,764,775,786,796,806,809,815,823,828,835,839,845,851,858,863,868,875,880,883,888,895,903,906,910,914,920,927,931,939,948,954,961,965,969,972,979,986,989,997,1003,1007,1013,1016,1019,1025,1028,1032,1037,1042,1047,1053,1059,1062,1068,1074,1077,1080,1084,1089,1096,1102,1111,1114,1116,1121,1129,1133,1137,1141,1144,1147,1151,1155,1164,1170,1173,1177,1186,1192,1196,1201,1205,1209,1214,1219,1223,1227,1231,1235,1239,1243,1248,1256,1265,1270,1274,1280,1283,1287,1291,1295,1302,1307,1312,1318,1324,1327,1333,1338,1345,1353,1358,1365,1372,1381,1386,1389,1392,1396,1402,1408,1415,1420,1423,1429,1433,1442,1446,1450,1454,1460,1463,1469,1475,1482,1486,1490,1497,1504,1508,1513,1519,1527,1533,1540,1547};

//-----------------------------------------------------
// DISABLED TO SAVE MEMORY (USE "wing1" ARRAYS INSTEAD)
//-----------------------------------------------------
//#define WING_1_SIZE 183
//#define WING_MASK_1_SIZE 109
//#define WING_2_SIZE 209
//#define WING_MASK_2_SIZE 82
//#define WING_3_SIZE 208
//#define WING_MASK_3_SIZE 83
//#define WING_4_SIZE 202
//#define WING_MASK_4_SIZE 89
//#define WING_5_SIZE 203
//#define WING_MASK_5_SIZE 88
//uint16_t wingMap1[WING_1_SIZE] = {0,1,2,7,8,9,10,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,45,46,62,63,64,65,66,67,68,69,70,71,72,73,74,75,80,81,91,92,93,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,126,127,128,129,130,131,133,134,135,136,137,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,173,174,175,176,177,178,180,181,182,183,184,188,189,190,191,192,193,194,195,196,197,198,199,200,205,206,216,217,218,222,223,224,225,226,227,237,238,254,255,256,257,258,259,260,261,266,267,268,269,271,272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,288,289,290};
//uint16_t wingMask1[WING_MASK_1_SIZE] = {3,4,5,6,11,36,37,38,39,40,41,42,43,44,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,76,77,78,79,82,83,84,85,86,87,88,89,90,94,95,96,121,122,123,124,125,132,138,139,140,168,169,170,171,172,179,185,186,187,201,202,203,204,207,208,209,210,211,212,213,214,215,219,220,221,228,229,230,231,232,233,234,235,236,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,262,263,264,265,270,};
//uint16_t wingMap2[WING_2_SIZE] = {0,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,44,45,46,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,79,80,81,82,83,91,92,93,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,199,200,201,204,205,206,207,208,216,217,218,222,223,224,225,236,237,238,254,255,256,257,258,259,264,265,266,267,268,269,270,271,272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,288,289,290};
//uint16_t wingMask2[WING_MASK_2_SIZE] = {1,2,3,4,34,35,36,37,38,39,40,41,42,43,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,77,78,84,85,86,87,88,89,90,94,95,96,202,203,209,210,211,212,213,214,215,219,220,221,226,227,228,229,230,231,232,233,234,235,239,240,241,242,243,244,245,246,247,248,249,250,251,252,253,260,261,262,263};
//uint16_t wingMap3[WING_3_SIZE] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,37,43,44,45,46,47,49,62,63,64,65,66,67,68,69,70,71,72,73,74,80,81,91,92,93,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,198,205,206,216,217,218,222,223,224,229,231,235,236,237,238,239,241,254,255,256,257,258,261,262,264,265,266,267,268,269,270,271,272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,288,289,290};
//uint16_t wingMask3[WING_MASK_3_SIZE] = {0,1,33,34,35,36,38,39,40,41,42,48,50,51,52,53,54,55,56,57,58,59,60,61,75,76,77,78,79,82,83,84,85,86,87,88,89,90,94,95,96,199,200,201,202,203,204,207,208,209,210,211,212,213,214,215,219,220,221,225,226,227,228,230,232,233,234,240,242,243,244,245,246,247,248,249,250,251,252,253,259,260,263};
//uint16_t wingMap4[WING_4_SIZE] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,36,37,38,42,43,44,45,46,47,48,49,50,59,61,62,63,64,65,66,67,69,70,71,72,91,92,93,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,170,171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,188,189,190,191,192,193,194,195,216,217,218,222,223,229,231,232,234,235,236,237,238,239,240,241,242,251,253,254,255,256,257,258,260,261,262,263,264,265,266,267,268,269,270,271,272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,288,289,290};
//uint16_t wingMask4[WING_MASK_4_SIZE] = {0,32,33,34,35,39,40,41,51,52,53,54,55,56,57,58,60,68,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,94,95,96,120,121,122,139,140,167,168,169,186,187,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,219,220,221,224,225,226,227,228,230,233,243,244,245,246,247,248,249,250,252,259};
//uint16_t wingMap5[WING_5_SIZE] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,35,36,37,38,39,41,42,43,44,45,46,47,48,49,50,51,52,55,58,59,60,61,62,63,64,65,66,70,71,91,92,93,94,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,116,117,118,125,126,127,128,129,130,131,133,134,135,136,137,141,142,143,144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,160,163,164,165,172,173,174,175,176,177,178,180,181,182,183,184,188,189,190,193,194,216,217,218,219,221,222,223,226,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,247,250,251,252,253,254,255,256,257,258,259,260,261,262,263,264,265,266,267,268,269,270,271,272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,288,289,290};
//uint16_t wingMask5[WING_MASK_5_SIZE] = {0,32,33,34,40,53,54,56,57,67,68,69,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,95,114,115,119,120,121,122,123,124,132,138,139,140,161,162,166,167,168,169,170,171,179,185,186,187,191,192,195,196,197,198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,220,224,225,227,228,245,246,248,249};

bool wing1[NUM_CRYSTALS] = {1,1,1,0,0,0,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
bool wing2[NUM_CRYSTALS] = {1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
bool wing3[NUM_CRYSTALS] = {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,1,0,1,0,0,0,1,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
bool wing4[NUM_CRYSTALS] = {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,1,1,0,0,0,0,0,1,0,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
bool wing5[NUM_CRYSTALS] = {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,1,1,1,1,1,1,1,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,0,0,1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

Graph * g;
int *dist;

// Time variables
uint8_t t = 0;
uint8_t timer = 0;
uint8_t timeDelta = 3;

// HSV variables 
// NOTE: uint8_t allows you to have a range 0-255 without having to mod any values (via 8-bit overflow)
uint8_t hue = 0;
uint8_t hueDelta = 1;

void setup() {

  // Initialises all ports as outputs (0 for output, 1 for input)
  // pins  0  ->  7
  DDRD = 0b00000000;
  // pins  8  -> 13
  DDRB = 0b00000000;
  // pins  14 -> 21
  DDRC = 0b00000000;
  Serial.begin(9600);

  digitalWrite(2, HIGH);

//  FastLED.addLeds<LED_TYPE, DATA_PIN0, RGB> (leds, 0, LEDS_PER_PIN);
//  FastLED.addLeds<LED_TYPE, DATA_PIN1, RGB> (leds, LEDS_PER_PIN, 40);
  // https://github.com/FastLED/FastLED/wiki/Multiple-Controller-Examples
//   FastLED.addLeds<LED_TYPE, DATA_PIN2, RGB> (leds, 2*LEDS_PER_PIN, LEDS_PER_PIN);

  
}

void loop() {
  
}
