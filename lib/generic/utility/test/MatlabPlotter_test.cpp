/**
 * \file lib/utility/MatlabPlotter_test.cpp
 * \version 1.0
 *
 * \section COPYRIGHT
 *
 * Copyright 2012 The Iris Project Developers. See the
 * COPYRIGHT file at the top-level directory of this distribution
 * and at http://www.softwareradiosystems.com/iris/copyright.html.
 *
 * \section LICENSE
 *
 * This file is part of the Iris Project.
 *
 * Iris is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * Iris is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * A copy of the GNU Lesser General Public License can be found in
 * the LICENSE file in the top-level directory of this distribution
 * and at http://www.gnu.org/licenses/.
 *
 * \section DESCRIPTION
 *
 * Main test file for MatlabPlotter class.
 */

#define BOOST_TEST_MODULE MatlabPlotter_Test

#include "MatlabPlotter.h"
#include <vector>
#include <boost/test/unit_test.hpp>
#include <boost/thread/thread.hpp>

using namespace std;

BOOST_AUTO_TEST_SUITE (MatlabPlotter_Test)

BOOST_AUTO_TEST_CASE(MatlabPlotter_Test_Scalar)
{
  vector<float> v(100);
  for(size_t i=0;i<100;i++)
    v[i] = i;

  MatlabPlotter *plotter,*plotter2;
  BOOST_REQUIRE_NO_THROW(plotter = new MatlabPlotter);
  BOOST_REQUIRE_NO_THROW(plotter2 = new MatlabPlotter);
  BOOST_CHECK_NO_THROW(plotter->plot(v.begin(), v.end()));
  BOOST_CHECK_NO_THROW(plotter2->plot(v.begin(), v.end()));
  delete plotter;
  delete plotter2;
  boost::this_thread::sleep(boost::posix_time::milliseconds(1000)); // Give the engine some time to close
}

BOOST_AUTO_TEST_CASE(MatlabPlotter_Test_Complex)
{
  vector<complex<float> > v(100);
  for(size_t i=0;i<100;i++)
    v[i] = complex<float>(i,i);

  MatlabPlotter *plotter,*plotter2;
  BOOST_REQUIRE_NO_THROW(plotter = new MatlabPlotter);
  BOOST_REQUIRE_NO_THROW(plotter2 = new MatlabPlotter);
  BOOST_CHECK_NO_THROW(plotter->plot(v.begin(), v.end()));
  BOOST_CHECK_NO_THROW(plotter2->plot(v.begin(), v.end()));
  delete plotter;
  delete plotter2;

}

BOOST_AUTO_TEST_SUITE_END()
