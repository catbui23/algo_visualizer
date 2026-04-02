#pragma once

class IAlgorithm {
public:
    virtual ~IAlgorithm() = default;
    virtual void start() = 0;

private:
    virtual void runAlgorithm() = 0;
    virtual void end() const = 0;
};
