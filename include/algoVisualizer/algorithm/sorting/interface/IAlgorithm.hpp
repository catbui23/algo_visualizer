#pragma once

class IAlgorithm {
public:
    virtual ~IAlgorithm() = default;
    virtual void start() = 0;

private:
    virtual void runStep() = 0;
    virtual void end() const = 0;
};
