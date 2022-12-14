#include "dinamicaRRR_capi_host.h"
static dinamicaRRR_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        dinamicaRRR_host_InitializeDataMapInfo(&(root), "dinamicaRRR");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}
