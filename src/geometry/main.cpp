
#define _CRTDBG_MAP_ALLOC
#include <osg/Group>
#include <osgViewer/Viewer>
#include "geometry.h"

#include "../common/CommonFunctions.h"



int main(int argc, char **argv)
{
	_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	TriGeom tg;

	
	osgViewer::Viewer *v = osgCookBook::getViewerWithSize(40,40,600,450);
	v->setSceneData(tg.GetRoot());
	
	v->run();

	delete v;
	return 1;
}