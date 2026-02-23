# tiny_template

Minimal string template engine for modern C++.

`tiny_template` provides a lightweight and clean API for replacing
`{{variables}}` inside strings using a simple key-value context.

It is designed for small services, config rendering, email generation,
static site preprocessing and backend templating.

Header-only. No heavy dependencies. No runtime magic.

## Why tiny_template?

Unlike full template engines, this library:

-   Supports simple `{{variable}}` replacement
-   Automatically trims spaces inside placeholders
-   Ignores missing keys safely
-   Is fully header-only
-   Has zero external dependencies
-   Keeps rendering deterministic and explicit

Perfect for:

-   Configuration file generation
-   Email templates
-   Static HTML rendering
-   CLI output formatting
-   Edge services
-   Lightweight backend systems


## Installation

### Using Vix Registry

``` bash
vix add gaspardkirira/tiny_template
vix deps
```

### Manual

Clone the repository:

``` bash
git clone https://github.com/GaspardKirira/tiny_template.git
```

Add the `include/` directory to your project.

## Quick Example

``` cpp
#include <tiny_template/tiny_template.hpp>
#include <iostream>

int main()
{
  using namespace tiny_template;

  Context ctx;
  ctx["name"] = "Alice";

  const std::string out =
    Engine::render("Hello {{name}}", ctx);

  std::cout << out << "\n";
}
```

Output:
```
    Hello Alice
```
## Multiple Variables Example

``` cpp
#include <tiny_template/tiny_template.hpp>
#include <iostream>

int main()
{
  using namespace tiny_template;

  Context ctx;
  ctx["first"] = "Gaspard";
  ctx["last"]  = "Kirira";
  ctx["role"]  = "builder";

  const std::string tpl =
    "Name: {{ first }} {{ last }}\n"
    "Role: {{role}}\n";

  std::cout << Engine::render(tpl, ctx);
}
```

## Missing Keys

If a variable does not exist in the context, it is replaced with an
empty string.

``` cpp
Engine::render("Hello {{unknown}}", ctx);
```

Result:
```
    Hello
```
This keeps rendering safe and predictable.

## Features

-   Header-only
-   C++17 compatible
-   Simple `{{variable}}` syntax
-   Automatic whitespace trimming
-   Safe handling of missing variables
-   Deterministic output
-   Minimal memory overhead
-   Easy to extend

## API Overview

``` cpp
tiny_template::Context ctx;
ctx["key"] = "value";

std::string result =
  tiny_template::Engine::render("{{key}}", ctx);
```

## Design Philosophy

tiny_template focuses on:

-   Simplicity over feature bloat
-   Explicit data flow
-   No logic, no conditions, no loops
-   No hidden behavior
-   Easy integration into existing systems

It intentionally does not provide:

-   Conditionals
-   Loops
-   Includes or partials
-   Expression evaluation
-   Script execution

It is meant to stay tiny.

## Tests

Run:

``` bash
vix build
vix tests
```

## License

MIT License
Copyright (c) Gaspard Kirira

