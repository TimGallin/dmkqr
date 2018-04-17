#ifndef DMKQR_HEADER_DMKQR
#define DMKQR_HEADER_DMKQR

#include <stdio.h>
#include <string>
#include <vector>

#include "tinyxml2/tinyxml2.h"


#define XML_ROOT "conf"

#define IMPL_PRESET_RASPUB "rsa_pubkey"
#define IMPL_PRESET_RASPRI "rsa_prikey"
#define IMPL_PRESET_AESKEY "aes_encryptkey"
#define IMPL_PRESET_DESKEY "des_encryptkey"

#define XML_IMPLICIT_PRESET "implpreset"
#define XML_SCHEME "scheme"
#define XML_SCHEME_VAR "variable"
#define XML_SCHEME_VAR_PRESET "preset"
#define XML_SCHEME_VAR_FORMULA "formula"


#define DMKQR_SUCCESS 0
#define DMKQR_FAILED -1
#define DMKQR_PARSE_ERROR -2

#define dmkqr_str2_cmp(m, c0, c1, c2)\
    m[0] == c0 && m[1] == c1

#define dmkqr_str3_cmp(m, c0, c1, c2)\
    m[0] == c0 && m[1] == c1 && m[2] == c2

#endif