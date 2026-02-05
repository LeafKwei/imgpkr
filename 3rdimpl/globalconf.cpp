#include "globalconf.h"

GlobalConf::GlobalConf() {

}

GlobalConf::GlobalConfCR GlobalConf::globalconf(){
    static GlobalConf globalconf;
    return globalconf;
}