#include "AComponent.h"
#include "Log.hpp"


DK_LOG_CATEGORY_DEFINE(COMPONENT_LOGGER)
DK_LOG_CATEGORY_DECLARE(COMPONENT_LOGGER, LoggerVerbosity::DEBUG)

using namespace drak;
using namespace components;

AComponent::AComponent()
{
}

AComponent::~AComponent()
{
}

Transform::Transform()
{
	id = ComponentID<Transform>();
}

Transform::~Transform()
{
}
