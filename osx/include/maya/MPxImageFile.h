#ifndef _MPxImageFile
#define _MPxImageFile
//-
// ==========================================================================
// Copyright (C) 1995 - 2006 Autodesk, Inc., and/or its licensors.  All
// rights reserved.
//
// The coded instructions, statements, computer programs, and/or related
// material (collectively the "Data") in these files contain unpublished
// information proprietary to Autodesk, Inc. ("Autodesk") and/or its
// licensors,  which is protected by U.S. and Canadian federal copyright law
// and by international treaties.
//
// The Data may not be disclosed or distributed to third parties or be
// copied or duplicated, in whole or in part, without the prior written
// consent of Autodesk.
//
// The copyright notices in the Software and this entire statement,
// including the above license grant, this restriction and the following
// disclaimer, must be included in all copies of the Software, in whole
// or in part, and all derivative works of the Software, unless such copies
// or derivative works are solely in the form of machine-executable object
// code generated by a source language processor.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND.
// AUTODESK DOES NOT MAKE AND HEREBY DISCLAIMS ANY EXPRESS OR IMPLIED
// WARRANTIES INCLUDING, BUT NOT LIMITED TO, THE WARRANTIES OF
// NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE,
// OR ARISING FROM A COURSE OF DEALING, USAGE, OR TRADE PRACTICE. IN NO
// EVENT WILL AUTODESK AND/OR ITS LICENSORS BE LIABLE FOR ANY LOST
// REVENUES, DATA, OR PROFITS, OR SPECIAL, DIRECT, INDIRECT, OR
// CONSEQUENTIAL DAMAGES, EVEN IF AUTODESK AND/OR ITS LICENSORS HAS
// BEEN ADVISED OF THE POSSIBILITY OR PROBABILITY OF SUCH DAMAGES.
// ==========================================================================
//+
//
// CLASS:    MPxImageFile
//
// ****************************************************************************

#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES


#include <maya/MObject.h>
#include <maya/MString.h>
#include <maya/MImage.h>
#include <maya/MTypes.h>
class MImageFileInfo;

// ****************************************************************************
// CLASS DECLARATION (MPxImageFile)

//! \ingroup OpenMaya MPx
//! \brief Image manipulation. 
/*!
  This class provides methods for reading file images stored on disk.

  The MPxImageFile class can be used to implement support for new image
  file formats in Maya. The implementation is able to support both fixed
  and floating point image formats.

  MPxImageFile allows custom image formats to be recognized by Maya and any 
  plug-ins that use Maya's API for accessing images. However be aware that 
  some third party plugins, such as mental ray, bypass Maya's API and use 
  their own internal facilities for accessing images, which means that they
  will not recognize MPxImageFile-based image formats. In the case of mental
  ray, it provides its own API which can be used to provide it with support
  for the image format.
*/
class OPENMAYA_EXPORT MPxImageFile
{
public:
					MPxImageFile();
					virtual	~MPxImageFile();
					virtual MStatus open( MString pathname, MImageFileInfo* info);
					virtual MStatus load( MImage& image, unsigned int imageNumber);
					virtual MStatus glLoad( const MImageFileInfo& info, unsigned int imageNumber);
					virtual MStatus close();

protected:
	// No protected members

private:

	void*			_instance;
};

#endif /* __cplusplus */
#endif /* _MPxImageFile */