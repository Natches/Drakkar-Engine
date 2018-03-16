#pragma once

#include <Core/Core.hpp>
#include <Core/Timer/ATimer.hpp>

namespace drak {
namespace time {

class FrameTimer : public ATimer {
	DK_NONMOVABLE_NONCOPYABLE(FrameTimer)
	friend drak::core::Engine;

public:
	float frameRate() const;
	float deltaTimeNoScale() const;
	float deltaTime() const;
	float timeScale() const;
	void timeScale(const float f);

	virtual void resume() override;
	virtual void pause() override;

private:
	FrameTimer();
	~FrameTimer() = default;
	virtual float duration(const TimeDuration duration_type = TimeDuration::AUTO,
		TimeDuration* duration_type_returned = nullptr) override;
	virtual void start() override;
	virtual void stop() override;
	virtual void reset(const bool enabled) override;
	void update();

private:
	float m_deltaTimeNoScale;
	float m_deltaTime;
	float m_timeScale;
};

} //namespace time
} //namespace drak