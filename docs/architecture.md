## System Overview

The CMS architecture is modular, with each component in its own repository:

- **cms-kernel (C++):** Core system, low-level APIs, resource management, security, and foundational services.
- **cms-bridge (Rust):** Handles plugin and theme management, scripting, SEO injection, and acts as the main extensibility layer.
- **Default themes:** Starter templates in various frontend frameworks, maintained in separate repos.

### Component Responsibilities

| Component      | Main Language | Responsibilities                                              |
|----------------|--------------|--------------------------------------------------------------|
| cms-kernel     | C++          | Core APIs, resource management, security, exposes interfaces |
| cms-bridge     | Rust         | Plugin manager, theme manager, scripting, SEO                |
| themes         | JS/TS/etc.   | Frontend presentation, custom logic                          |

The **Theme Manager** and **Plugin Manager** are implemented in the Rust bridge. The kernel provides the core services and interfaces they use.
