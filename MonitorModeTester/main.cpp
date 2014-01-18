#include <iostream>
#include <fstream>
#include <d3d9.h>

int main()
{
	std::cout<<"Monitor tester\n";

	IDirect3D9* d3dObject = Direct3DCreate9(D3D_SDK_VERSION);
	D3DFORMAT fmt = D3DFMT_X8R8G8B8;
	std::ofstream out;
	out.open("modes.inf");

	int adapterCount = d3dObject->GetAdapterCount();
	for (int i = 0; i < adapterCount; ++i)
	{
		int modeCount = d3dObject->GetAdapterModeCount(i, fmt);
		std::cout<<"Found "<<modeCount<<" modes\n";
		for (int j = 0; j < modeCount; ++j)
		{
			D3DDISPLAYMODE mode;
			d3dObject->EnumAdapterModes(i, fmt, j, &mode);
			out<<mode.Height<<"x"<<mode.Width<<"@"<<mode.RefreshRate<<std::endl;
		}
	}
	out.close();
	return 0;
}