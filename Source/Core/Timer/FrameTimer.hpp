#pragma once

#include <Core/Timer/ATimer.hpp>

namespace drak {
namespace core {
class Engine;
}
namespace time {

class FrameTimer : public ATimer {
	DK_NONMOVABLE_NONCOPYABLE(FrameTimer)
	friend core::Engine;
public:
	F32 frameRate() const;
	F32 deltaTimeNoScale() const;
	F32 deltaTime() const;
	F32 timeScale() const;
	void timeScale(const F32 f);

	virtual void resume() override;
	virtual void pause() override;
private:
	FrameTimer();
	~FrameTimer() = default;
	virtual F32 duration(const TimeDuration duration_type = TimeDuration::AUTO,
		TimeDuration* duration_type_returned = nullptr) override;
	virtual void start() override;
	virtual void stop() override;
	virtual void reset(const bool enabled) override;
	void update();

private:
	F32 m_deltaTimeNoScale;
	F32 m_deltaTime;
	F32 m_timeScale;
};

} //namespace time
} //namespace drak