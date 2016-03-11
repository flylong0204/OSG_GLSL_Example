
#include <osg/ShapeDrawable>
#include <osg/Geode>
#include <osgViewer/Viewer>
#include <osg/MatrixTransform>
#include "../common/CommonFunctions.h"


class SetShapeColorHandler : public osgCookBook::PickHandler
{
	virtual void doUserOperations( osgUtil::LineSegmentIntersector::Intersection& result )
	{
		osg::ShapeDrawable *shape = dynamic_cast<osg::ShapeDrawable*>(result.drawable.get());
		if (shape)
			shape->setColor(osg::Vec4(1.0f, 1.0f, 1.0f, 2.0f) - shape->getColor());
	}

};

osg::Node* createMatrixTransform(osg::Geode *geode, const osg::Vec3& pos)
{
	osg::ref_ptr<osg::MatrixTransform> trans = new osg::MatrixTransform;
	trans->setMatrix(osg::Matrix::translate(pos));
	trans->addChild(geode);
	return trans.release();
}


int main(int argc, char **argv)
{

	osg::ref_ptr<osg::ShapeDrawable> sphereShape = new osg::ShapeDrawable(new osg::Sphere);
	sphereShape->setColor(osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f));
	sphereShape->setDataVariance(osg::Object::DYNAMIC);
	sphereShape->setUseDisplayList(false);

	osg::ref_ptr<osg::Geode> g0 = new osg::Geode;
	g0->addDrawable(sphereShape.get());

	osg::ref_ptr<osg::Geode> g1 = dynamic_cast<osg::Geode*>(g0->clone(osg::CopyOp::SHALLOW_COPY));
	osg::ref_ptr<osg::Geode> g2 = dynamic_cast<osg::Geode*>(g0->clone(osg::CopyOp::DEEP_COPY_ALL));

	osg::ref_ptr<osg::Group> root = new osg::Group;
	root->addChild(createMatrixTransform(g0.get(), osg::Vec3(0.0f,0.0f,0.0f)));
	root->addChild(createMatrixTransform(g1.get(), osg::Vec3(-2.0f,0.0f,0.0f)));
	root->addChild(createMatrixTransform(g2.get(), osg::Vec3(2.0f,0.0f,0.0f)));

	osg::ref_ptr<osgText::Text> text = new osgText::Text;
	text->setText("Hello,this is test hudCamera.");
	text->setCharacterSize(10);
	text->setPosition(osg::Vec3(0,0,0));

	osg::ref_ptr<osg::Geode> gText = new osg::Geode;
	gText->addDrawable(text);

	osg::Camera* hudCamera = osgCookBook::createHUDCamera(0,800,0,500);
	hudCamera->addChild(gText);
	root->addChild(hudCamera);

	osgViewer::Viewer viewer;
	viewer.addEventHandler(new SetShapeColorHandler());
	viewer.setSceneData(root);


	return viewer.run();
}
