#include "qdbmp_1.0.0/qdbmp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMG_WIDTH 2968
#define IMG_HEIGHT 1854

void checkCoordinates(BMP* file);

float lookup[291][2] = {{2133,1552},{2132,1846},{2047,1972},{2119,2083},{2228,2012},{2320,2181},{2091,2208},{2089,2408},{2230,2342},{2345,2451},{2440,2337},{2524,2169},{2691,2310},{2593,2435},{2859,2417},{3099,2416},{3240,2366},{3382,2450},{3596,2419},{3489,2260},{3234,2202},{3243,2008},{3257,1845},{3464,1884},{3422,2078},{3605,2063},{3685,1900},{3895,1859},{3890,2052},{3698,2175},{3883,2256},{3861,2413},{2081,1394},{2303,1414},{2351,1554},{2250,1704},{2330,1861},{2418,2028},{2505,1889},{2417,1724},{2492,1570},{2583,1722},{2680,1857},{2604,2018},{2747,2128},{2949,2283},{3015,2085},{2810,1979},{2868,1828},{3049,1917},{3065,1772},{2876,1659},{2750,1687},{2690,1514},{2863,1475},{3050,1601},{3031,1368},{3166,1299},{3397,1430},{3399,1570},{3213,1502},{3236,1684},{3481,1710},{3713,1680},{3624,1489},{3862,1438},{3910,1635},{2076,1230},{2270,1253},{2261,1107},{2167,988},{2343,881},{2469,956},{2560,1051},{2460,1196},{2478,1295},{2612,1301},{2604,1420},{2894,1299},{2793,1175},{2710,1032},{2850,886},{3047,950},{2977,1064},{3112,1131},{3276,1073},{3274,899},{3486,839},{3476,998},{3643,942},{3676,805},{3836,803},{3936,895},{3799,1028},{3585,1147},{3413,1205},{3482,1325},{3761,1287},{3921,1171},{2000,1092},{2102,842},{2000,658},{2133,540},{2312,398},{2427,309},{2373,116},{2592,61},{2731,174},{2701,327},{2563,378},{2537,558},{2299,563},{2273,741},{2465,729},{2671,761},{2805,648},{2735,551},{2861,437},{3086,449},{3035,620},{3009,787},{3144,793},{3335,746},{3261,622},{3403,504},{3304,362},{3145,280},{2911,213},{3013,62},{3254,99},{3455,132},{3438,262},{3522,343},{3680,278},{3642,84},{3844,46},{3901,195},{3818,410},{3607,494},{3553,683},{3724,591},{3790,642},{3928,625},{3952,442},{1898,842},{1867,540},{1882,340},{2118,340},{2133,114},{1867,114},{1688,398},{1573,309},{1627,116},{1408,61},{1269,174},{1299,327},{1437,378},{1463,558},{1701,563},{1727,741},{1535,729},{1329,761},{1195,648},{1265,551},{1139,437},{914,449},{965,620},{991,787},{856,793},{665,746},{739,622},{597,504},{696,362},{855,280},{1089,213},{987,62},{746,99},{545,132},{562,262},{478,343},{320,278},{358,84},{156,46},{99,195},{182,410},{393,494},{447,683},{276,591},{210,642},{72,625},{48,442},{1924,1230},{1739,1107},{1833,988},{1657,881},{1531,956},{1440,1051},{1540,1196},{1730,1253},{1697,1414},{1522,1295},{1388,1301},{1396,1420},{1106,1299},{1207,1175},{1290,1032},{1150,886},{953,950},{1023,1064},{888,1131},{724,1073},{726,899},{514,839},{524,998},{357,942},{324,805},{164,803},{64,895},{201,1028},{415,1147},{587,1205},{518,1325},{239,1287},{79,1171},{1919,1394},{1867,1552},{1750,1704},{1649,1554},{1508,1570},{1772,2012},{1583,1724},{1582,2028},{1495,1889},{1417,1722},{1320,1857},{1396,2018},{1253,2128},{1051,2283},{985,2085},{1190,1979},{1132,1828},{951,1917},{935,1772},{1124,1659},{1250,1687},{1310,1514},{1137,1475},{950,1601},{969,1368},{834,1299},{603,1430},{601,1570},{787,1502},{764,1684},{519,1710},{287,1680},{376,1489},{138,1438},{90,1635},{2000,1700},{1868,1846},{1953,1972},{1881,2083},{1670,1861},{1680,2181},{1909,2208},{1911,2408},{1770,2342},{1655,2451},{1560,2337},{1476,2169},{1309,2310},{1407,2435},{1141,2417},{901,2416},{760,2366},{618,2450},{404,2419},{511,2260},{766,2202},{757,2008},{743,1845},{536,1884},{578,2078},{395,2063},{315,1900},{105,1859},{110,2052},{302,2175},{117,2256},{139,2413}};

int main(int argc, char* argv[]) {

    if(argc != 2) {
        printf("Enter in the name of file to convert. For example, use:\n"
               "./compile_run myImage.bmp\n");
        return EXIT_FAILURE;
    }

    char outputName[100];
    sprintf(outputName, "%s", argv[1]);
    char *ret = NULL;

    ret = strstr(outputName, ".bmp");
    if(ret == NULL) {
        printf("Input file must be in (.bmp) format.\n");
        return EXIT_FAILURE;      
    }

    strcpy(ret, ".txt");

    BMP* image = NULL;
    image = BMP_ReadFile(argv[1]);
    if(image == NULL) {
        printf("Input file not found.\n");
        return EXIT_FAILURE;
    }
    FILE *f = fopen(outputName, "w");

    int x, y;
    UCHAR r, g, b;

    printf("{");
    fprintf(f, "{");
    for(int i = 0; i < 291; i++) {

        x = lookup[i][0]/4000*IMG_WIDTH;
        y = lookup[i][1]/4000*IMG_WIDTH;
        BMP_GetPixelRGB(image, x , y, &r, &g, &b);        
        printf("{%d,%d,%d", r, g, b);
        fprintf(f, "{%d,%d,%d", r, g, b);
        if(i != 290) {
            printf("},");
            fprintf(f, "},");
        }
    }
    printf("}};\n");
    fprintf(f, "}};\n");

    BMP_Free(image);
    fclose(f);

    return EXIT_SUCCESS;
}

// Shows which points are being sampled for the converter
void checkCoordinates(BMP* file) {
    for(int i = 0; i < 291; i++) {
        printf("%d\n", i);
        for(int j = -10; j < 10; j++) {
            for(int k = -10; k < 10; k++) {
                BMP_SetPixelRGB(file, lookup[i][0]/4000*IMG_WIDTH + j, lookup[i][1]/4000*IMG_WIDTH + k, 230, 230, 230);
                if(j == k || j == - k) {
                    BMP_SetPixelRGB(file, lookup[i][0]/4000*IMG_WIDTH + j, lookup[i][1]/4000*IMG_WIDTH + k, 0, 0, 0);
                }
            }
        }
    }
}