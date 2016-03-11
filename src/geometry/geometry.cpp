#include "geometry.h"


TriGeom::TriGeom()
{
	osg::ref_ptr<osg::Vec3Array> vt = new osg::Vec3Array(3);
	(*vt)[0].set(-5, 0, 0);
	(*vt)[1].set(5, 0, 0);
	(*vt)[2].set(0,10,0);

	osg::ref_ptr<osg::Vec3Array> colorArray = new osg::Vec3Array(3);
	(*colorArray)[0].set(1, 0, 0);
	(*colorArray)[1].set(0, 1.0, 0);
	(*colorArray)[2].set(0,0,1);


	osg::ref_ptr<osg::Geometry> geo = new osg::Geometry();
	geo->setVertexArray(vt.get());
	geo->setColorArray(colorArray.get());
	geo->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
	geo->addPrimitiveSet(new osg::DrawArrays(GL_TRIANGLE_STRIP, 0, 3));

	m_Root = new osg::Geode;
	m_Root->addDrawable(geo);


}

TriGeom::~TriGeom()
{

}

osg::Geode *TriGeom::GetRoot()
{
	if (m_Root.valid()) 
		return m_Root.release();
	else
		return NULL;
}


