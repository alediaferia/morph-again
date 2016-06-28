#ifndef UI_ELEMENT_H
#define UI_ELEMENT_H

#include <strings>
#include <memory>

class UiElement {
public:
    UiElement();
    UiElement(std::weak_ptr<UiElement> parent);
    virtual ~UiElement();

    std::weak_ptr<UiElement> parent() const;
    virtual std::string toString() const;

private:
    std::shared_ptr<UiElement> _parent;
};

#endif // UI_ELEMENT_H
