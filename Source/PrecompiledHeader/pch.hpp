#pragma once

#include "./../ThirdParty/glew-2.0.0/include/GL/glew.h"

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <array>
#include <tuple>
#include <fstream>
#include <sstream>
#include <iostream>
#include <ostream>
#include <type_traits>
#include <ctime>
#include <cmath>
#include <limits>
#include <algorithm>
#include <cassert>
#include <immintrin.h>
#include <io.h>
#include <direct.h>
#include <chrono>
#include <thread>

#include <Core/Core.hpp>
#include <Core/Utils/FileUtils.hpp>
#include <Core/Timer/FrameTimer.hpp>
#include <Core/Components/GameObject.hpp>
#include <Core/Utils/VA_ArgsUtils.hpp>
#include <Core/Utils/AComponentUtils.hpp>

#include <Serialization/MetaData.hpp>
#include <Serialization/Serializer.hpp>

#include <Math/Quaternion.hpp>
#include <Math/MathUtils.hpp>
#include <Math/SIMDUtils.hpp>
#include <Math/Vec2.hpp>
#include <Math/Vec3.hpp>
#include <Math/Vec4.hpp>
#include <Math/Vec8.hpp>
#include <Math/Matrix4x4.hpp>

#include <Engine/Components/Components.hpp>
#include <Engine/Components/TransformComponent.hpp>
#include <Engine/Components/ModelComponent.hpp>
#include <Engine/Components/PhysicsComponents.hpp>
#include <Engine/Components/ABehavior.hpp>

#include <Engine/Scene/LevelSystem.hpp>
#include <Engine/Scene/LevelSystemUtils.hpp>

#include <Threading/Function/IFunction.hpp>
#include <Threading/Function/IndicesTrick.hpp>
#include <Threading/Function/Function.hpp>

#include <Threading/Thread/StealableQueue/StealableQueue.hpp>
#include <Threading/Thread/ThreadObject.hpp>
#include <Threading/Thread/ThreadPool.hpp>
#include <Threading/Thread/TimeThread.hpp>

#include <Threading/Timer/Timer.hpp>
#include <Threading/Timer/BenchmarkTimer.hpp>

#include <Threading/Task/ATask.hpp>
#include <Threading/Task/Task.hpp>
#include <Threading/Task/DeferredTask.hpp>
#include <Threading/Task/DelayedTask.hpp>
#include <Threading/Task/RecurentTask.hpp>
#include <Threading/Task/TaskGroup.hpp>
#include <Threading/Task/TaskSequence.hpp>

#include <Video/Graphics/Common/Color.hpp>

#include <Video/Graphics/Geometry/Base/AMesh.hpp>
#include <Video/Graphics/Geometry/Mesh.hpp>
#include <Video/Graphics/Geometry/Vertex.hpp>

#include <Video/Graphics/Tools/AssetSceneImporter.hpp>

#include <Video/Graphics/Rendering/Base/IFrameBuffer.hpp>
#include <Video/Graphics/Rendering/Base/IRenderable.hpp>
#include <Video/Graphics/Rendering/Base/IRenderer.hpp>
#include <Video/Graphics/Rendering/Base/IShader.hpp>
#include <Video/Graphics/Rendering/Base/IRenderTarget.hpp>

#include <Video/Graphics/Rendering/OpenGL/GLFrameBuffer.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLIndexBuffer.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLObject.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLRenderer.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLShader.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLTexture.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLTypes.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLVertexArray.hpp>
#include <Video/Graphics/Rendering/OpenGL/GLVertexBuffer.hpp>

#include <Video/Graphics/Rendering/Camera.hpp>
#include <Video/Graphics/Rendering/RenderSystem.hpp>

#include <Video/VideoSettings.hpp>
#include <Video/VideoSystem.hpp>

#include <Windowing/Input/Keyboard.hpp>
#include <Windowing/Window/AWindow.hpp>
#include <Windowing/Window/WindowSettings.hpp>