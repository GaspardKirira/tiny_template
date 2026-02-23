#include <tiny_template/tiny_template.hpp>
#include <iostream>

int main()
{
  using namespace tiny_template;

  Context ctx;
  ctx["name"] = "Alice";

  const std::string out =
      Engine::render("Hello {{name}} - {{unknown}}", ctx);

  std::cout << out << "\n";
  return 0;
}
