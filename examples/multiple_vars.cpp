#include <tiny_template/tiny_template.hpp>
#include <iostream>

int main()
{
  using namespace tiny_template;

  Context ctx;
  ctx["first"] = "Gaspard";
  ctx["last"] = "Kirira";
  ctx["role"] = "builder";

  const std::string tpl =
      "Name: {{ first }} {{ last }}\n"
      "Role: {{role}}\n";

  const std::string out =
      Engine::render(tpl, ctx);

  std::cout << out;
  return 0;
}
