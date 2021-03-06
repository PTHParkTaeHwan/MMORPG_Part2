#include "pch.h"
#include "EnginePch.h"
#include "Engine.h"

//unique_ptr<Engine> GEngine;

void Engine::Init(const WindowInfo& info)
{
	_window = info;
	ResizeWindow(info.width, info.height);

	// 그려질 화면 크기를 설정
	_viewport = { 0, 0, static_cast<FLOAT>(info.width), static_cast<FLOAT>(info.height), 0.0f, 1.0f };
	_scissorRect = CD3DX12_RECT(0, 0, info.width, info.height);

	_device = make_shared<Device>();
	_cmdQueue = make_shared<CommandQueue>();
	_swapChain = make_shared<SwapChain>();
	_rootSignature = make_shared<RootSignature>();
	_cb = make_shared<ConstantBuffer>();
	_tableDescHeap = make_shared<TableDescriptorHeap>();

	_device->Init();
	_cmdQueue->Init(_device->GetDevice(), _swapChain);
	_swapChain->Init(info, _device->GetDevice(), _device->GetDXGI(), _cmdQueue->GetCmdQueue());
	_rootSignature->Init(_device->GetDevice());
	_cb->Init(sizeof(Transform), 256);
	_tableDescHeap->Init(256);

}

void Engine::Render()
{
	RenderBegin();

	//todo

	RenderEnd();
}

void Engine::RenderBegin()
{
	_cmdQueue->RenderBegin(&_viewport, &_scissorRect);
}

void Engine::RenderEnd()
{
	_cmdQueue->RenderEnd();
}

void Engine::ResizeWindow(int32 width, int32 height)
{
	_window.width = width;
	_window.height = height;

	RECT rect = { 0, 0, width, height  };
	::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);  
	::SetWindowPos(_window.hwnd, 0, 100, 100, _window.width, _window.height, 0);
	//:: 글로벌 네임스페이스에서 찾겠다는 의미, 없어도 되지만 윈도우제공이라는것 암시
}
