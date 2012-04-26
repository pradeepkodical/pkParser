/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Jan 09 17:14:31 2009
 */
/* Compiler settings for C:\Pradeep\C++\PkParserLib\PkParserCom\PkParserCom.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IParser = {0x907ED02C,0xCE17,0x4E01,{0x97,0xED,0x22,0x82,0x45,0x58,0xB9,0x48}};


const IID LIBID_PKPARSERCOMLib = {0x617C0661,0xA339,0x4861,{0x8D,0x0A,0x88,0x24,0x8D,0xF2,0xAE,0xB4}};


const CLSID CLSID_Parser = {0x3844108D,0xF043,0x4DE1,{0xA8,0xCF,0x0F,0x73,0x6C,0xC2,0x9A,0x01}};


#ifdef __cplusplus
}
#endif

