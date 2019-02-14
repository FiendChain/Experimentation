#pragma once

namespace bc
{

class Timer
{
    private:
        long long m_LastUpdate;
        unsigned m_Duration;
    public:
        Timer(unsigned duration);
        inline void SetDuration(unsigned duration) { m_Duration = duration; }
        inline unsigned GetDuration() const { return m_Duration; }
        bool Check();
        void Reset();
};

}
