#include <map>
#include <iostream>


typedef void (*ScriptFunction)(void); // function pointer type
typedef std::map<std::string, ScriptFunction> script_map;

void some_function(void)
{
}

int main() {
    script_map m;
    m.insert(std::make_pair("blah", &some_function));
}

