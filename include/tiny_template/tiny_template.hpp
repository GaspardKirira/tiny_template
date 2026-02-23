#pragma once

/**
 * @file tiny_template.hpp
 * @brief Minimal string template engine (header-only).
 *
 * Supports:
 *   - {{variable}} replacement
 *   - Missing keys replaced by empty string
 *   - No logic, no loops, no conditions
 *
 * Example:
 *   "Hello {{name}}" -> "Hello Alice"
 */

#include <string>
#include <string_view>
#include <unordered_map>

namespace tiny_template
{
  using Context = std::unordered_map<std::string, std::string>;

  class Engine final
  {
  public:
    /**
     * @brief Render template using provided context.
     */
    static std::string render(std::string_view input, const Context &ctx)
    {
      std::string output;
      output.reserve(input.size());

      std::size_t i = 0;

      while (i < input.size())
      {
        if (i + 1 < input.size() &&
            input[i] == '{' &&
            input[i + 1] == '{')
        {
          std::size_t end = input.find("}}", i + 2);
          if (end == std::string_view::npos)
          {
            // malformed -> append rest
            output.append(input.substr(i));
            break;
          }

          std::string key(input.substr(i + 2, end - (i + 2)));

          // trim spaces
          trim(key);

          auto it = ctx.find(key);
          if (it != ctx.end())
            output.append(it->second);

          i = end + 2;
        }
        else
        {
          output.push_back(input[i]);
          ++i;
        }
      }

      return output;
    }

  private:
    static void trim(std::string &s)
    {
      const auto not_space = [](unsigned char c)
      {
        return !std::isspace(c);
      };

      while (!s.empty() && std::isspace(static_cast<unsigned char>(s.front())))
        s.erase(s.begin());

      while (!s.empty() && std::isspace(static_cast<unsigned char>(s.back())))
        s.pop_back();
    }
  };
}
