#include <tiny_template/tiny_template.hpp>
#include <iostream>
#include <cstdlib>

static void expect(bool cond, const char *msg)
{
  if (!cond)
  {
    std::cerr << "Test failed: " << msg << "\n";
    std::exit(1);
  }
}

int main()
{
  using namespace tiny_template;

  Context ctx;
  ctx["name"] = "Alice";
  ctx["age"] = "30";

  {
    std::string result =
        Engine::render("Hello {{name}}", ctx);

    expect(result == "Hello Alice", "basic replacement failed");
  }

  {
    std::string result =
        Engine::render("Age: {{ age }}", ctx);

    expect(result == "Age: 30", "trim failed");
  }

  {
    std::string result =
        Engine::render("Missing: {{unknown}}", ctx);

    expect(result == "Missing: ", "missing key failed");
  }

  {
    std::string result =
        Engine::render("No template here", ctx);

    expect(result == "No template here", "plain text failed");
  }

  std::cout << "tiny_template: all tests passed\n";
  return 0;
}
