#pragma once

#include "RHIDescriptorHeap.h"
#include "RHIResourceView.h"
#include "RHIShader.h"
#include "RHICommandBuffer.h"
#include "RHISwapChain.h"
#include "Render/RenderCore/Public/VisualBuffer.h"
#include "Game/Asset/Public/Scene.h"
#include "Game/Asset/Public/ShaderLab.h"
#include "Game/Asset/Public/Mesh.h"
#include "Game/Asset/Public/Texture.h"
#include "Game/GamePlay/Public/Camera.h"
#include "Game/GamePlay/Public/Light.h"
#include <memory>

using namespace Lumen::Game;

namespace Lumen::Render
{
    struct WindowInfo
    {
        void*               mainWnd = nullptr;
        int                 clientWidth = 1920;
        int                 clientHeight = 1080;
    };

    struct ProfileData
    {
        float               gameThreadTickTime;
        float               renderThreadTickTime;
    };

    class RHIContext
    {
    public:
        // Switch frame resource and wait for gpu fence
        virtual void BeginFrame() = 0;

        // Signal fence and reset allocator
        virtual void EndFrame() = 0;

        virtual RHICommandBuffer* RequestCmdBuffer(const EContextType& type, std::string_view name) = 0;

        virtual void ReleaseCmdBuffer(RHICommandBuffer* cmdBuffer) = 0;

        virtual void ExecuteCmdBuffer(RHICommandBuffer* cmdBuffer) = 0;

        virtual void Present() = 0;

        virtual void UpdateObjectCB(const Entity& entity) = 0;

        virtual void UpdatePassCB(const Camera& camera, const DirectionalLight& light) = 0;

        virtual void RenderScene(uint32_t width, uint32_t height) = 0;

        virtual void DrawUI(void* data) = 0;

        // Create scene buffer for display
        virtual void CreateSceneBuffer(VisualBuffer* buffer) = 0;

        // Create texture
        virtual void CreatePlainTexture(Texture& texture) = 0;

        // Create cubemap
        virtual void CreateCubeMap(std::vector<Texture>& textures) = 0;

        // Create geometry
        virtual void CreateGeometry(const Mesh& mesh) = 0;

        // Create shaders
        virtual void CreateShaderlab(const ShaderLab& shaderlab) = 0;

        // Create render item
        virtual void CreateRenderItem(const Entity& entity) = 0;

        // Create sky render item
        virtual void CreateSkyItem() = 0;

        virtual RHICommandContext* GetContext(const EContextType& type) = 0;
    };
}