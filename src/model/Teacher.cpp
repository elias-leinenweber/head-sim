#include <string>

#include "imgui/imgui-SFML.h"
#include "imgui/imgui.h"

#include "model/Actor.h"
#include "model/Teacher.h"

static int
getImageID(int a, int b)
{
    return (a * b) % 3 + 1;
}

Teacher::Teacher(const std::string &firstname, const std::string &surname,
                 double pedagogie, double meritocratic)
  : Actor(firstname, surname,
          "resources/images/profs/prof" +
            std::to_string(getImageID(pedagogie, meritocratic)) + ".png")
  , pedagogue(pedagogie)
  , meritocratic(meritocratic)
{
}

void
Teacher::clickPopup()
{
    if (ImGui::MenuItem("Afficher fiche information"))
        infoSheet();
}

void
Teacher::infoSheet()
{
    // TODO
}
