#ifndef UI_ELEMENT_H
#define UI_ELEMENT_H

#include <string>
#include <memory>

class UiElement {
public:
    UiElement();
    UiElement(const std::weak_ptr<UiElement> &parent);
    virtual ~UiElement();

    void setName(const std::string &name);
    std::string name() const;

    std::weak_ptr<UiElement> parent() const;
    virtual std::string toString() const;

private:
    std::shared_ptr<UiElement> _parent;
};

#endif // UI_ELEMENT_H

