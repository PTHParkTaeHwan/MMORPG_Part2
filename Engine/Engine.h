#pragma once

#include "Device.h"
#include "CommandQueue.h"
#include "SwapChain.h"
#include "RootSignature.h"
#include "Mesh.h"
#include "Shader.h"
#include "ConstantBuffer.h"
#include "TableDescriptorHeap.h"

class Engine
{
public:
	void Init(const WindowInfo& info);
	void Render();

public:
	shared_ptr<Device> GetDevice() { return _device; } //gpu에 접근할 때 사용, 핵심
	shared_ptr<CommandQueue> GetCmdQueue() { return _cmdQueue; }//gpu에 요청 보낼 때 모아서 보내기 위한 수단
	shared_ptr<SwapChain> GetSwapChain() { return _swapChain; } //더블 버퍼링 용도
	shared_ptr<RootSignature> GetRootSignature() { return _rootSignature; }
	shared_ptr<ConstantBuffer> GetCB() { return _cb; }
	shared_ptr<TableDescriptorHeap> GetTableDescHeap() { return _tableDescHeap; }

public:
	void RenderBegin();
	void RenderEnd();

	void ResizeWindow(int32 width, int32 height);
private:
	//그려질 화면 크기 관련
	WindowInfo _window;
	D3D12_VIEWPORT _viewport = {};
	D3D12_RECT _scissorRect = {};

	//초기화에 필요한 부분들
	shared_ptr<Device> _device; //gpu에 접근할 때 사용, 핵심
	shared_ptr<CommandQueue> _cmdQueue; //gpu에 요청 보낼 때 모아서 보내기 위한 수단
	shared_ptr<SwapChain> _swapChain; //더블 버퍼링 용도
	shared_ptr<RootSignature> _rootSignature;
	shared_ptr<ConstantBuffer> _cb;
	shared_ptr<TableDescriptorHeap> _tableDescHeap;

};

