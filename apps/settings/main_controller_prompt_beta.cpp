#include "main_controller.h"
#include "../exam_mode_configuration.h"
#include <apps/i18n.h>

namespace Settings {

constexpr SettingsMessageTree s_modelMenu[] =
  {SettingsMessageTree(I18n::Message::MathOptions, s_modelMathOptionsChildren),
    SettingsMessageTree(I18n::Message::Brightness),
    SettingsMessageTree(I18n::Message::FontSizes, s_modelFontChildren),
    SettingsMessageTree(I18n::Message::Language),
    SettingsMessageTree(I18n::Message::ExamMode, ExamModeConfiguration::s_modelExamChildren),
    SettingsMessageTree(I18n::Message::BetaPopUp),
    SettingsMessageTree(I18n::Message::About, s_modelAboutChildren),
    SettingsMessageTree(I18n::Message::Accessibility, s_accessibilityChildren)};

constexpr SettingsMessageTree s_model = SettingsMessageTree(I18n::Message::SettingsApp, s_modelMenu);

I18n::Message MainController::promptMessage() const {
  return I18n::Message::BetaPopUp;
}

}
