/**
 * \file RawFileUtility.h
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
 * class providing static functions for reading/writing data to/from files.
 */

#ifndef RAWFILEUTILITY_H
#define RAWFILEUTILITY_H

#include <fstream>
#include "EndianConversion.h"

/*! \class RawFileUtility Class
* \brief This class provides generic functionality for reading and writing signals to and from files.
*/
class RawFileUtility
{
public:

	/*! Function Description.
	* \brief Write anything to file
	* \param first An iterator to the first element 
	* \param last An iterator to the last element
	* \param filename Name of file to write data to
	* \param endianness	The endianness with which data should be written
	*/
	template <typename Iter>
	static bool write(Iter first, Iter last, std::string filename, std::string endianness = "native")
	{
		using namespace std;

		string fileName(filename);
		fileName += ".bin";

		ofstream hOutFile(fileName.c_str(), ios::binary | ios::trunc);
		// file will be closed during deconstruction

		if(hOutFile.is_open())
		{
			return write(first, last, hOutFile, endianness);
		}
		else
			return false;
	};

	/*! Function Description.
	* \brief Write anything to file
	* \param first		An iterator to the first element 
	* \param last		An iterator to the last element
	* \param hOutFile	An ofstream to write to
	* \param endianness	The endianness with which data should be written
	*/
	template <typename Iter>
	static bool write(Iter first, Iter last, std::ostream &hOutFile, std::string endianness = "native")
	{
		using namespace std;

		for(;first != last;++first)
		{
			typename iterator_traits<Iter>::value_type temp = *first;
			if(sizeof(temp) > 1)
			{
				if(endianness == "big")
				{
					temp = sys2big(temp);
				}
				if(endianness == "little")
				{
					temp = sys2lit(temp);
				}
			}
			hOutFile.write(reinterpret_cast<char*>(&temp), sizeof(temp));
		}
		return true;
	};
};

#endif

