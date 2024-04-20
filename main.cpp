#include "rdengine.h"

int main(int argc, char *argv[])
{
	RDEngine* engine = new RDEngine();

	engine->Init();

	while(!engine->ShouldClose())
	{
		engine->Update();
		engine->Render();
		engine->Rest(5);
	}
	
	return 0;
}

END_OF_MAIN();