// -*- mode:C++; tab-width:8; c-basic-offset:2; indent-tabs-mode:t -*-
// vim: ts=8 sw=2 smarttab
/*
 * Ceph - scalable distributed file system
 *
 * Copyright (C) 2016 Michael Sevilla <mikesevilla3@gmail.com>
 *
 * This is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 2.1, as published by the Free Software
 * Foundation.  See file COPYING.
 *
 */

#ifndef CEPH_MANTLE_H
#define CEPH_MANTLE_H

#include <lua.hpp>
#include <list>
#include <map>

#include "include/types.h"
#include "common/Clock.h"
#include "CInode.h"

class Mantle {
  protected:
    lua_State *L;
    map<mds_rank_t, mds_load_t>  mds_load;

  public:
    Mantle() : L(NULL) {};
    int start();
    int execute(string script);
    int balance(string script,
                mds_rank_t whoami,
                vector < map<string, double> > metrics,
                map<mds_rank_t,double> &my_targets);
};

#endif
