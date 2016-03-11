#pragma once

#include <osg/Geometry>
#include <osg/Geode>

class TriGeom
{
public:
	TriGeom();
	~TriGeom();

	osg::Geode *GetRoot();

protected:
	osg::ref_ptr<osg::Geode> m_Root;
};
