# Output Explained

- Constructor global   [[ gfoo is being created ]]
- Constructor local    [[ afoo is being created ]]
- Copy Constructor     [[ bfoo is being create from afoo - compiler calls CC]]
- **Copy Constructor     [[ a copy of gfoo is being created to return from getAFoo() ]]**
- **What is this member function called? [[ cfoo is being created - compiler calling MC ]]**
- **Destructor global    [[ copy of gfoo is being deleted (it's data was moved to cfoo) ]]**
- Copy Constructor     [[ copy of bfoo created to call operator=() - called from lvalue ]]
- = Operator           [[ afoo = bfoo ]]
- Destructor local     [[ copy of bfoo being deleted]]
- Destructor global    [[ cfoo is being deleted ]]
- Destructor local     [[ bfoo or afoo is being deleted but likely bfoo ]]
- Destructor local     [[ bfoo or afoo is being deleted but likely afoo  ]]
- Destructor global    [[ gfoo is being deleted ]]

## Without the std::move

[Copy Elision](https://en.wikipedia.org/wiki/Copy_elision)

- Constructor global   [[ gfoo is being created ]]
- Constructor local    [[ afoo is being created ]]
- Copy Constructor     [[ bfoo is being create from afoo - compiler calls CC]]
- **Copy Constructor     [[ cfoo is being created - Copy elision]]**
- Copy Constructor     [[ copy of bfoo created to call operator=() - called from lvalue ]]
- = Operator           [[ afoo = bfoo ]]
- Destructor local     [[ copy of bfoo being deleted]]
- Destructor global    [[ cfoo is being deleted ]]
- Destructor local     [[ bfoo or afoo is being deleted but likely bfoo ]]
- Destructor local     [[ bfoo or afoo is being deleted but likely afoo  ]]
- Destructor global    [[ gfoo is being deleted ]]
