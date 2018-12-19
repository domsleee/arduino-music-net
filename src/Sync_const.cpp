#include "Sync.hpp"

static void Sync::sync_const_master();
static void Sync::sync_const_slave();

void Sync::sync_const() {
  if (this->type == MASTER) {
    sync_const_master();
  }
  else {
    sync_const_slave();
  }
}

static void Sync::sync_const_master() {

}

static void Sync::sync_const_slave() {
  
}

