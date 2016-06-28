#include "ui_element.h"

UiElement::UiElement(std::weak_ptr<UiElement> parent) : UiElement() {
    if ((_parent = parent.lock())) {
      // success!!
    }
}

std::string UiElement::toString() const {
    return std::sprintf("UiElement(%x)", this);
}
