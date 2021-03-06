// -*- Mode: C++ -*-

//          RTpredicate.cpp
//
// Copyright (c) 1996, Regents of the University of California
// $Header: /usr/local/devel/GiST/libGiST/RTree/RTpredicate.cpp,v 1.1.1.1 1996/08/06 23:47:26 jmh Exp $

#include "RT.h"

int 
RTpredicate::Consistent(const GiSTentry& entry) const
{
  RTentry &rtentry = (RTentry &)entry;

  if (entry.IsLeaf()) {
    switch (oper) {
    case RToverlap:
      return(rtentry.Key().overlap((RTkey)value));
      break;
    case RTcontains:
      return(rtentry.Key().contain((RTkey)value));
      break;
    case RTcontained:
      return(rtentry.Key().contained((RTkey)value));
      break;
    case RTEqual:
      return(rtentry.Key() == ((RTkey)value));
      break;
    default:
      assert(0);
      return (0);
      break;
    }
  }
  else {
    switch (oper) {
    case RToverlap:
    case RTcontained:
      return(rtentry.Key().overlap((RTkey)value));
      break;
    case RTcontains:
    case RTEqual:
      return(rtentry.Key().contain(((RTkey)value)));
      break;
    default:
      assert(0);
      return (0);
      break;
    }
  }
}

