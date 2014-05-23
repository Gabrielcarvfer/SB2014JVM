//
//  data_management.h
//  jvm
//
//

#ifndef jvm_data_management_h
#define jvm_data_management_h

/*
 Máscaras e Macros de conversão de tipo
 */
#define _1F 0x0000001fh
#define _3F 0x0000003fh
#define _0F 0x0000000fh

#define LSBY_MASK(x)  (x&0x000000FF) //Máscara do byte menos significativo
#define MLSBY_MASK(x) (x&0x0000FF00) //Máscara do byte intermediario menos significativo
#define MHSBY_MASK(x) (x&0x00FF0000) //Máscara do byte intermediario mais significativo
#define HSBY_MASK(x)  (x&0xFF000000) //Máscara do byte mais significativo

//Macro de conversão de U2 de big-endian para little-endian e vice-versa
#define U2_LB(x) (LSBY_MASK(x)<<8)
#define U2_HB(x) (MLSBY_MASK(x)>>8)
#define U2_CONVERTION(x) (x=(U2_LB(x)|U2_HB(x)))

//Macro de conversão de U4 de big-endian para little-endian e vice-versa
#define U4_LB(x)  (LSBY_MASK(x)<<24)
#define U4_MLB(x) (MLSBY_MASK(x)<<8)
#define U4_MHB(x) (MHSBY_MASK(x)>>8)
#define U4_HB(x)  (HSBY_MASK(x)>>24)
#define U4_CONVERTION(x) (x=(U4_LB(x)|U4_MLB(x)|U4_MHB(x)| U4_HB(x)))

//Macro de conversão de 2 U1 para UTF-8
#define UTF8_2U1_CONVERTION(X,Y) (((X&_1F)<<6)+(Y&_3F))
#define UTF8_3U1_CONVERTION(X,Y,Z) (((X&_0F)<<12)+((Y&_3F)<<6)+(Z&_3F))
/*
 Definição de Tipos
 */

//Tipos JVM
typedef uint8_t  u1;
typedef uint16_t u2;
typedef uint32_t u4;

/*
 Funções
 */
//void convertLittleBigEndianu2(u2 * mp);
//void convertLittleBigEndianu4(u4 * mp);
u1 readu1(FILE * fp);
u2 readu2(FILE * fp);
u4 readu4(FILE * fp);
#endif
