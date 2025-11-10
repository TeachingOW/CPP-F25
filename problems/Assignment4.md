
# Assignment III: JSON Schema Analyzer

This assignment involves building a tool that analyzes a JSON document and infers its schema.

---

## **Objective**

Write a program that takes a JSON file as an argument and performs the following:

1. Reads the JSON document from the provided file.  
2. Analyzes the document structure to identify the schema (attribute names).  
3. For each attribute in the schema, infers its data type based on the values present in the document.

---

## **Possible Data Types**

- **String**  
- **Number** (Integer or Float)  
- **Boolean**  
- **Array** (collection of values of the same or different types)  
- **Object** (nested structure)

---

## **Output**

The program should display the inferred schema in a user-friendly format.  
Here’s an example:

### **Schema:**

- **name:** (String)  
- **age:** (Number)  
- **hobbies:** (Array of Strings)  
- **address:** (Object)  
  - **street:** (String)  
  - **city:** (String)  
  - **zip:** (String)

---

## **Implementation**

You must implement this tool in **C/C++**. Here are some key points to consider:

- Use [SimdJson](https://github.com/simdjson/simdjson) for parsing JSON data.  
- Documentation of the library and quick start can be found [here](
https://simdjson.org/api/0.4.0/index.html).
- Recursively traverse the JSON document to explore nested structures.  
- During traversal, keep track of encountered attributes and their corresponding values.  
- Based on the value types encountered (string, number, boolean, array, object), infer the data type for each attribute.  
- A recursive example of processing a JSON document can be found here:  
  [recursive_print_json example](https://github.com/simdjson/simdjson/blob/master/doc/basics.md)

---

## **Evaluation**

Your program will be evaluated based on the following criteria:

- **Correctness:** Does the program accurately identify the schema and infer data types?  
- **Readability:** Is the code well-structured and easy to understand?  
- **Bonus:** Points will be awarded for error handling and additional features.

---

## **Tips**

- Start by working on simple JSON documents and gradually increase complexity.  
- Use debugging tools to inspect the structure of the JSON data during traversal.  
- You can use the example code ([quickstart](https://github.com/TeachingOW/simdjson-quickstart)) to see how to use the library in Visual Studio.  
- You can work in **teams**.

---

## **Compilation Instructions**

### **For macOS/Linux**
To compile:
```bash
g++ quickstart.cpp simdjson.cpp 
```
### in Windows
Add all files to the project
