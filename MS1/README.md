# Project: Ontario Pre-Triage Application for Healthcare Facilities
## Current Project State
- MS1 & MS2 release <br /> V1.2 Clarified the insertion and extraction operator overloads
- MS3 & MS4 release<br />V1.1 MS4 (removed deprecated methods, `csvRead and csvWrite`)

## Milestones

|Milestone| Revision | Comments |
|------|:---:|:----|
| [MS1](#milestone-1) | V1.0 |  |
| [MS2](#milestone-2) | V1.0 |    |
| [MS3](#milestone-3) | V1.0  |    |
| [MS4](#milestone-4) | V1.0  |   |
| [MS5](#milestone-5) | V1.0 |   |


## Use case

 In the event of a pandemic, measures must be taken to prevent the spread of the contagion. healthcare facilitys are required to screen patients and separate those in need of contagion testing from others. This process must be conducted in an orderly manner, informing patients of the expected wait time and notifying them when they can be admitted.

Your task is to assist in completing the implementation of the Pre-Triage application, which will be used in such scenarios.

### The Pre-Triage Application
The application starts by displaying a simple menu with three options:
```Text
Ontario Pre-Triage Application for Healthcare Facilities
1- Register
2- Admit
0- Exit
>
```
#### Register
The register option is selected to screen patients before getting into the healthcare facility. The user can select between a contagion Test or Triage.

Contagion test is selected if the patient is at the healthcare facility for a contagion Test. In this case, the patient's name and OHIP number is entered and then a ticket will be printed with a call number and estimated wait time for admission for the patient.

If Triage is selected then in addition to the patient's name and OHIP number, the symptoms of the patient are entered. Then a ticket for Triage is printed with an estimated wait time for admission.

#### Admit
Admit is selected when the contagion Test area or the Triage section is ready to accept a patient. After selecting contagion or Triage, the patient with the next ticket in line will be called. Based on the time of the call, the average wait time for the next patient for that line up (contagion or Triage) will be updated.





# Milestones

|Milestone| Revision |Comments |
|------|:---:|:----|
| [MS1](#milestone-1) | V1.0 | |
| [MS2](#milestone-2) | V1.0 | |
| [MS3](#milestone-3) | V1.0 | |
| [MS4](#milestone-4) | V1.0 |  |
| [MS5](#milestone-5) | V1.0 |  |



## Milestones due dates
This project will be completed in five milestones, with each milestone having a specified due date. The due date for each milestone is determined based on the amount of work required to achieve it.

To ensure successful completion of the project within the given timeframe, I recommend starting early and diligently meeting all the milestone due dates.

> Remember: Early preparation and timely progress are key to project success. Best of luck with your project! 

## Final project mark and due dates

|Milestone| Mark | Due date | Submission Policy|
|:------:|:---:|:---:|-------|
| MS1 | 10% | Mar 13 | Mandatory to submit<br />gets full mark even if 1 week late. gets 0% afterwards, **Rejected After Apr 8th**|
| MS2 | 10% | Mar 16 | Mandatory to submit<br />gets full mark even if 1 week late. gets 0% afterwards, **Rejected After Apr 8th**|
| MS3 | 10% | Mar 24 | Mandatory to submit<br />gets full mark even if 1 week late. gets 0% afterwards, **Rejected After Apr 8th**|
| MS4 | 10% | Mar 30 | Mandatory to submit<br />gets full mark even if 1 week late. gets 0% afterwards, **Rejected After Apr 8th**|
| MS5 | 60% | See below| See below|

### Milestone 5 submissions
- **Due date**: Apr 8th
- Project submission **rejection date**: Apr 13th 23:59
- Late Submission Penalty: A 10% deduction per day will be applied for late submissions, up to a maximum of 5 days. After 5 days, the submission will receive a mark of zero.

> To facilitate the final project submission and allow partial submissions, we have divided Milestone 5 into six smaller parts. Each submission contributes 10% to the overall project grade. Your project will be evaluated only if you have completed all four milestones and submitted at least one of the six parts for Milestone 5. 

|Milestone 5<br/> Divided into<br/>Six submission| Description | Comments |
|:------|:---|-------|
| [m51](#milestone-51) |  | Mandatory, this is needed for the rest<br /> of the options to be functional|
| [m52](#milestone-52) |  | Optional with 10% penalty |
| [m53](#milestone-53) |  | Optional with 10% penalty |
| [m54](#milestone-54) |  | Optional with 10% penalty |
| [m55](#milestone-55) |  | Optional with 10% penalty |
| [m56](#milestone-56) |  | Optional with 10% penalty |


#### Milestones 1 to 4: Success and Timely Submissions
- The first four milestones will not be evaluated based on the code itself. Instead, their assessment will focus on success (meeting project objectives) and timely submissions. During these milestones, you have the flexibility to modify or debug your previous code as needed.
- If you require any feedback on your first four milestones you need to ask your professor to do so.
#### Milestone 5: Code Scrutiny
- **Milestone** 5 is the critical phase where your code will be closely examined. Ensure that your implementation aligns with project requirements and best practices. 

***NOTE:***<br/>
**Your project will receive a mark of zero if any of the milestones are not submitted by [the rejection date](#milestone-5-submissions)<br />For your project to be marked, you must submit all the first 4 milestones and at least part 1 of the 6 submissions of Milestone 5**

### Checking Due dates using the submitter program


You can check the due date of each milestone using the ```-due``` flag in the submission command when the submissions are set up:
```bash
~profname.proflastname/submit 2??/prj/m? -due
```
- replace **2??** with the subject code
- replace **m?** with the milestone number

## Citation, Sources

When submitting your work, all the files submitted should carry full student information along with the "citation and sources" information. See the following example:

If you have multiple submissions of the same milestone, please update the Revision History in each submission so your professor knows what changes to look for.

```c++
/* Citation and Sources...
Final Project Milestone ? 
Module: Whatever
Filename: Whatever.cpp
Version 1.0
Author   John Doe
Revision History
-----------------------------------------------------------
Date      Reason
2023/?/?  Preliminary release
2023/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and 
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
```

**Failing to include the above citation to any of the files containing your work will cause the rejection of your project submission**

## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the c++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as follows to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ws
```

- `--show-error-list=yes`: show the list of detected errors
- `--leak-check=full`: check for all types of memory problems
- `--show-leak-kinds=all`: show all types of memory leaks identified (enabled by the previous flag)
- `--track-origins=yes`: tracks the origin of uninitialized values (`g++` must use `-g` flag for compilation, so the information displayed here is meaningful).

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

> All the code written in the project must be implemented in the **seneca** namespace.

> Make sure that all the debugging code and debugging comments are removed before submission.

## Project Implementation notes:  *Very Important, read carefully*

### 1- Namespace Requirement:
- All code written for this project must be within the seneca namespace.
### 2- Flexibility in Adding Attributes and Methods:
- You are encouraged to add any necessary attributes (member variables), functions, and methods (member functions) to complete your code.
- If unsure about your strategy for adding functionalities and properties to your classes, seek advice from your professor.
### 3- Private Methods:
- If you add methods that are not called outside the scope of the class, ensure they are set as private.
### 4- Naming Conventions:
- Unless explicitly instructed otherwise, name variables and functions as you find fit.
- Follow the naming conventions provided by your professor and subject notes
- Meaningless or misleading names may result in penalties.
### 5- Constant Member Functions:
- When creating methods (member functions), set them as constant if they do not modify their class.
### 6- Passing by Address or Reference:
- When passing an object or variable by address or reference, use constant pointers and references if they are not meant to be modified.
### 7- Empty State Consideration:
- If an empty state is required for an object, it should be considered an “invalid” empty state.
Objects in this state should be rendered unusable.
### 8- Utils Module:
- A module named Utils is included in the project.
- If you don’t have custom functionalities, leave the Utils module as is.
- You can add your own code to the Utils module, but do not modify existing functionalities provided for testing and system time retrieval purposes.
### 9- Code Reuse:
- You may reuse and copy any code provided by your professor in workshops or functions from previous work in this subject or other subjects.
- Place such code in the Utils module as needed and cite it.
### 10 - Display and Input Methods

- For any class that requires a display or print functionality, the method should adhere to the following format, unless specified otherwise:
   ```c++
   ostream& displayMethod(ostream& ostr = cout) const;
   ```
   This displayMethod function takes an ostream reference as an argument, with a default value of cout. It returns an ostream reference, allowing for chained insertion operations. The const qualifier ensures that the method does not modify any class members.

- For any class that requires scanning or reading from input, the method should adhere to the following format, unless specified otherwise:
   ```c++
   istream& readMethod(istream& istr = cin);
   ```
   The readMethod function takes an istream reference as an argument, with a default value of cin. It returns an istream reference, enabling chained extraction operations. This method is used to read or scan data into the class members.

   These methods provide a standard interface for output and input operations, enhancing the usability and flexibility of your classes.
 


# Milestone 1 

## Utils Module
The `Utils` module is a versatile component of your project. It currently includes methods for retrieving system time. In debugging mode, the system time is simulated to facilitate testing and development.

The module is designed with extensibility in mind. You are encouraged to add custom methods and functionalities to this module or class as needed. This approach promotes code reuse and helps maintain consistent logic across your project.

The `Utils` module is instantiated globally, making it accessible to any module that includes “Utils.h”. It is available under the alias `U`. This global availability ensures that its methods can be conveniently used wherever needed in your project.

Remember to refer to the comments within the module for a deeper understanding of how it operates. These comments can serve as a valuable guide as you work with the Utils module or extend its capabilities.

## Startup

To initiate the project, we will develop two modules: `Time` and `Menu`. The `Time` module will manage the progression of time and add timestamps to appointment tickets. The `Menu` module drives the main user interface of the application.

## Time Module
The first step in tracking time for issued tickets is to implement a Time class.

The `Time` class is designed to:
- Read and write time in HH:MM format.
- Measure the passage of time.
- Calculate the estimated wait time.

The `Time` module stores time solely in minutes (one attribute for minutes). However, it displays and reads time in the `HH:MM` format. For instance, if the `Time` object holds the value ***125***, it will display as ***02:05***. Similarly, if the time ***13:55*** is read by the Time object from istream, it stores ***835*** in the object (i.e., 13x60+55). Note that the `Time` object can also be used to measure the passage of time, and there is no limit to the number of minutes it can hold. It can exceed 24 hours if necessary.

> Note: ***125:15*** is a valid time that represents 125 hours and 15 minutes. Also, ***0:96*** is a valid entry and it is displayed as ***01:36***, which is ***1*** hour and ***36*** minutes.

Complete the implementation of the Time class with the following mandatory specs:  

### Attributes
The Time has one mandatory attribute to keep number of minutes. 

### Methods

```c++
Time& reset();  
```
This method resets the `Time` object to the current time using the `U.getTime()` method, which is available in the Utils module. It then returns a reference to the current object.

> Note: If the `seneca::debug` flag is set to true, or if the `U.setDebugTime()` method is called, the `U.getTime()` function will return a simulated system time. This feature is useful for debugging purposes and when submitting your work through the submitter program.

```c++
Time(unsigned int min = 0u); 
```
This constructor initializes a `Time` object. It sets the number of minutes held in the object to the value provided in the min parameter. If no value is provided, it defaults to zero, effectively setting the time to zero.

```c++
write
```
This method writes the time into ostream in the `HH:MM` format. If the hours or minutes are single-digit numbers, it pads them with a leading zero. For example, it formats the times as `03:02`, `16:55`, and `234:06`.


```c++
read
```
This method reads the time from istream in the `H:M` format. It ensures that the two integers (hours and minutes) are separated by a colon (`:`). If they are not, it sets the istream object to a failure state.

Please note that this function does not handle any invalid data. It simply follows these steps:

- Reads the integer for the hours using istream.
- Check the next character and verifies if it is `:` and discards is. If it is not, it sets the istream object to a failure state by executing the method: `istr.setstate(ios::failbit);`.
- Reads the integer for the minutes using istream.

- >Note: Do not clear or flush the istream as this method adheres to the istream standards. The caller of this function may check the istream state to ensure that the read operation was successful, if necessary.

```c++
operator unsigned int()const;
```
This operator overloads the cast to `unsigned int` for the `Time` class. If a `Time` object is cast to an unsigned integer, it will return the number of minutes held in the object.

```c++
Time& operator*= (int val);
```
This operator overloads the multiplication assignment `*=` for the `Time` class. It multiplies the number of minutes held in the Time object by val, then returns a reference to the current object.

```c++
Time& operator-= (const Time& D);
```

This operator overloads the subtraction assignment `-=` for the `Time` class. It calculates the time difference between the current Time object and the Time object `D` passed as an argument. Note that the difference can never be a negative value. If the result would be negative, it adds 24 hours (or 1440 minutes) to ensure the result is positive. Here are some examples:

- `23:00 -= 9:00` results in `14:00`.
- `18:00 -= 16:00` results in `2:00`.
- `1:00 -= 22:00` results in `3:00`. This is calculated as ((**1:00** + 24:00) - **22:00**).

See the illustration below:
![Time](images/time.png)

```c++
Time operator-(const Time& T)const;
```
This operator performs the same calculation as the subtraction assignment `-=` overload, except that it does not have a side effect (i.e., it does not modify the current object).

It returns a new `Time` object representing the time difference between the current `Time` object and the `Time` object `T`.

### Helper Insertion and Extraction Overloads

```c++
operator<<
```
Overload the insertion operator to be able to insert a Time object into an ostream object as described in the write method.
```c++
operator>>
```
Overload the extraction operator to be able to extract data from an istream object into the Time object as described in the read method.

## Time Tester
The following program is a tester for the Time class.

[timeTester.cpp](ms1/timeTester.cpp)


## Menu Module
Create a Menu class that encapsulates a menu and provides selection functionality for the caller program.

### Suggested attributes
- A constant char pointer to hold the content of the menu to be displayed
- An Integer to hold the number of options in the menu
- An integer to hold the number of indetation tabs


```c++
 Menu(const char* menuContent, int numberOfTabs = 0);
```
This constructor is designed to initialize a `Menu` object. It takes two parameters: a pointer to a character string `menuContent`, and an optional integer `numberOfTabs` with a default value of `0`.

The constructor dynamically allocates memory to store the content pointed to by `menuContent` in the member variable `m_text`. It then scans `m_text` to count the number of newline characters (`\n`), which is used to determine the number of options in the menu.

The `numberOfTabs` parameter specifies the number of indentation tabs to be applied when displaying the menu. This allows for flexible formatting of the menu display. If not provided, no tabs will be applied by default.

```c++
 ~Menu();
```
Deallocates the dynamically allocated memory.

```Text
Copy and assignment
```
Makes sure the Menu can not be copied or assigned to another Menu object.

```text
display
```

The display method is responsible for presenting the `Menu` content to the user. It first outputs the menu options and a new line. Following the list of options, it prints:

```text
0- Exit
> _
```
This provides an option for the user to exit the menu and also indicates where the user can input their choice.

If the number of tabs attribute is not zero, the display method will indent the menu. Each tab corresponds to three spaces. This allows for adjustable formatting of the menu display.

Here are examples of how the menu would be displayed:

A menu with no indentation (i.e., `number of tabs` is `0`):

```text
Tester Options menu:
1- Option one
2- Option two
0- Exit
>
```
A menu with `number of tabs` set to`2`:
```text
      Tester Options menu:
      1- Option one
      2- Option two
      0- Exit
      >
```
In the second example, each line of the menu is indented by six spaces (two tabs * three spaces per tab) for a more structured visual presentation. This feature enhances the flexibility and user-friendliness of your menu system.

```c++
int& operator>>(int& Selection);
```
The member insertion operator first calls the display function and then receives the user's selection as an integer value. The integer reference **selection** argument is then set to this value and returned.<br />
Make sure that the entered value is validated as an integer (with no trailing characters) and also the value should be between 0 and the **number of options** in the menu.<br />
If the above conditions are not met, a proper error message should be displayed and re-entry requested(see below)

Assuming that the menu content is set to:```"Tester Options menu:\n1- Option one\n2- Option two\n3- Option three"``` , (hence the number of selections will 3) the **operator>>** should run like this:
```Text
Tester Options menu:
1- Option one
2- Option two
3- Option three
0- Exit
> abc
Bad integer value, try again: 1 (with a space after 1)
Only enter an integer, try again: -1
Invalid value enterd, retry[0 <= value <= 3]: 4
Invalid value enterd, retry[0 <= value <= 3]: 2
```
`2` is returned as user's selection.

## Menu Tester
[menuTester.cpp](ms1/menuTester.cpp)

## MS1 Submission 
> If you would like to successfully complete the project and be on time, **start early** and try to meet all the due dates of the milestones.

### MS1 Tester Progtram

[main.cpp](ms1/main.cpp)

### MS1 Expected Output

[correct_output.txt](ms1/correct_output.txt)

### Submission

Upload your source code and the tester program to your `matrix` account. Compile and run your code using the `g++` compiler [as shown in the introduction](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 2??/prj/m?
```
and follow the instructions.

- *2??* is replaced with your subject code
- *m?* is replaceed with the milestone name (i.e. m1, m2, etc...)

### The submit program's options:
```bash
~prof_name.prof_lastname/submit DeliverableName [-submission options]<ENTER>
[-submission option] acceptable values:
  "-due":
       Shows due dates only
       This option cannot be used in combination with any other option.
  "-skip_spaces":
       Do the submission regardless of incorrect horizontal spacing.
       This option may attract penalty.
  "-skip_blank_lines":
       Do the submission regardless of incorrect vertical spacing.
       This option may attract penalty.
  "-feedback":
       Check the program execution without submission.
```

## [Back to milestones](#milestones)
