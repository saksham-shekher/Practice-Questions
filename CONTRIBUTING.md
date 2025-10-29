# Contributing to Practice-Questions

Thank you for your interest in contributing to the Practice-Questions repository! This guide will help you contribute effectively.

## 🎯 How Can You Contribute?

We welcome contributions in the following areas:

1. **New Programming Problems** - Add new fundamental problems commonly asked in junior developer interviews
2. **Additional Languages** - Implement existing problems in other languages (JavaScript, C++, Go, Rust, etc.)
3. **Alternative Solutions** - Add different approaches to solve existing problems
4. **Pattern Programs** - Add new pattern printing programs
5. **Algorithms** - Add new searching or sorting algorithms
6. **Documentation** - Improve README files, add explanations, fix typos
7. **Learning Resources** - Suggest quality beginner-friendly resources
8. **Bug Fixes** - Fix issues in existing code

## 📋 Contribution Guidelines

### Code Style and Standards

#### General Requirements
- **Code Quality**: Write clean, readable, and well-commented code
- **Multiple Methods**: For each problem, provide at least 2-3 different implementation approaches
- **Complexity Analysis**: Include time and space complexity in comments
- **Testing**: Ensure your code runs without errors and produces correct output
- **Documentation**: Add clear docstrings/comments explaining what each method does

#### Language-Specific Style Guides

**Python:**
- Follow PEP 8 style guidelines
- Use meaningful variable names
- Add docstrings to all functions
- Include type hints where appropriate
- Example:
  ```python
  def function_name(param: int) -> int:
      """
      Brief description of what the function does.
      
      Time Complexity: O(n)
      Space Complexity: O(1)
      """
      # Implementation
  ```

**Java:**
- Follow Java naming conventions (camelCase for methods, PascalCase for classes)
- Add Javadoc comments
- Use meaningful class and method names
- Example:
  ```java
  /**
   * Brief description of what the method does.
   * Time Complexity: O(n)
   * Space Complexity: O(1)
   */
  public static int methodName(int param) {
      // Implementation
  }
  ```

**C:**
- Follow K&R or GNU style
- Add function comments
- Use meaningful variable names
- Free allocated memory properly
- Example:
  ```c
  /**
   * Brief description of what the function does.
   * Time Complexity: O(n)
   * Space Complexity: O(1)
   */
  int function_name(int param) {
      // Implementation
  }
  ```

### File Structure

When adding new problems, follow this structure:

```
Language-Folder/
├── problem_name.ext          # Main implementation file
├── README.md                 # Update with new problem info
```

For patterns or algorithms:
```
Topic-Folder/
├── implementation.ext        # Add to existing file or create new
├── README.md                 # Update with new addition
```

### Naming Conventions

- **Python files**: `snake_case.py` (e.g., `reverse_string.py`)
- **Java files**: `PascalCase.java` (e.g., `ReverseString.java`)
- **C files**: `snake_case.c` (e.g., `reverse_string.c`)
- **Functions/Methods**: Descriptive names that explain what they do

## 🚀 How to Contribute

### Step 1: Fork the Repository

1. Click the "Fork" button at the top right of this repository
2. Clone your forked repository:
   ```bash
   git clone https://github.com/YOUR_USERNAME/Practice-Questions.git
   cd Practice-Questions
   ```

### Step 2: Create a Branch

Create a new branch for your contribution:
```bash
git checkout -b feature/your-feature-name
```

Use descriptive branch names:
- `feature/add-reverse-string`
- `fix/palindrome-bug`
- `docs/update-readme`

### Step 3: Make Your Changes

1. **Add your code** following the guidelines above
2. **Test your code** thoroughly:
   ```bash
   # Python
   python your_file.py
   
   # Java
   javac YourFile.java
   java YourFile
   
   # C
   gcc your_file.c -o output
   ./output
   ```
3. **Update documentation** if you're adding new problems or features
4. **Verify formatting** and style

### Step 4: Commit Your Changes

Write clear, concise commit messages:
```bash
git add .
git commit -m "Add reverse string problem with 3 methods"
```

**Good commit messages:**
- `Add bubble sort implementation in Python`
- `Fix off-by-one error in binary search`
- `Update README with new pattern examples`

**Bad commit messages:**
- `Update`
- `Fix bug`
- `Changes`

### Step 5: Push and Create Pull Request

1. Push your changes:
   ```bash
   git push origin feature/your-feature-name
   ```

2. Go to the original repository on GitHub
3. Click "New Pull Request"
4. Select your branch and submit the PR

### Pull Request Guidelines

**Your PR should include:**
- Clear title describing what was added/fixed
- Description of changes made
- Which languages are affected
- Any new dependencies (if applicable)
- Test results showing the code works

**PR Template:**
```markdown
## Description
Brief description of what this PR adds or fixes

## Type of Change
- [ ] New problem/algorithm
- [ ] Bug fix
- [ ] Documentation update
- [ ] New language implementation

## Languages Affected
- [ ] Python
- [ ] Java
- [ ] C
- [ ] Other (specify)

## Testing
- [ ] Code runs without errors
- [ ] All methods produce correct output
- [ ] Added test cases in main function

## Checklist
- [ ] Code follows style guidelines
- [ ] Comments and documentation added
- [ ] Complexity analysis included
- [ ] README updated (if needed)
```

## 📝 Adding New Problems

### Problem Selection Criteria

Good problems for this repository should:
- Be commonly asked in junior developer interviews
- Have multiple solution approaches
- Be fundamental (not advanced algorithms)
- Be language-agnostic (can be implemented in multiple languages)
- Have clear input/output expectations

### Implementation Checklist

When adding a new problem:

- [ ] Create the file in Python/, Java/, and C/ folders
- [ ] Implement at least 3 different methods
- [ ] Add time and space complexity comments
- [ ] Include test cases in main/if __name__ == "__main__"
- [ ] Update the respective README.md in each folder
- [ ] Update main README.md with the new problem
- [ ] Test all implementations
- [ ] Ensure consistent formatting

### Example Template

**Python:**
```python
"""
Problem Name - Multiple Methods
Brief description of the problem
"""

def method_one(param):
    """
    Method 1: Description
    Time Complexity: O(?)
    Space Complexity: O(?)
    """
    # Implementation
    pass

def method_two(param):
    """
    Method 2: Description
    Time Complexity: O(?)
    Space Complexity: O(?)
    """
    # Implementation
    pass

if __name__ == "__main__":
    # Test cases
    print("Testing problem_name")
    # Add test examples
```

## 🐛 Reporting Issues

If you find a bug or have a suggestion:

1. **Check existing issues** to avoid duplicates
2. **Create a new issue** with:
   - Clear, descriptive title
   - Steps to reproduce (for bugs)
   - Expected vs actual behavior
   - Language/file affected
   - Your environment (OS, language version)

## 📚 Documentation Contributions

Documentation is crucial! You can help by:

- Improving existing explanations
- Adding more examples
- Fixing typos or grammar
- Adding diagrams or visual aids
- Updating the learning resources list
- Translating documentation (if multilingual support is added)

## ❓ Questions?

If you have questions about contributing:

1. Check existing issues and discussions
2. Read the main README.md
3. Review existing code for examples
4. Open an issue with the "question" label

## 🎓 First Time Contributors

New to open source? No problem!

- Start with documentation fixes or typos
- Add test cases to existing problems
- Implement existing problems in a new language
- Check issues labeled "good first issue"

Resources for first-time contributors:
- [First Contributions Guide](https://github.com/firstcontributions/first-contributions)
- [How to Contribute to Open Source](https://opensource.guide/how-to-contribute/)

## 📜 Code of Conduct

### Our Standards

- Be respectful and inclusive
- Welcome beginners and help them learn
- Provide constructive feedback
- Focus on what is best for the community
- Show empathy towards others

### Unacceptable Behavior

- Harassment or discriminatory language
- Trolling or insulting comments
- Publishing others' private information
- Other conduct inappropriate in a professional setting

## ⚖️ License

By contributing to this repository, you agree that your contributions will be licensed under the same license as the project (if specified) or made available for educational purposes.

## 🙏 Recognition

Contributors will be recognized in:
- Git commit history
- GitHub contributors page
- Special mentions for significant contributions

---

**Thank you for contributing to Practice-Questions! Your efforts help aspiring developers learn and grow.** 🚀

For any questions or clarifications, feel free to open an issue or reach out to the maintainers.
