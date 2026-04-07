#pragma once

class IVisualizer {
public:
    virtual void render() const = 0;
    virtual void printHeader() const = 0;
    virtual ~IVisualizer() = default;

private:
    virtual void resetFrame() const = 0;
    virtual void printFinalFrame() const = 0;
};
