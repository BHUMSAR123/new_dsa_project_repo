
*Sleep Inducer*
This program simulates a music sleep inducing system where students are assigned to dormitories based on their sleep schedules, and sleep-inducing music is played for them during their sleep time. It also allows users to view the details of inmates in dormitories or execute the sleep inducer.

*Features:*
- *Inserting Student Details*: The program reads student records from an input file and populates the system with student details including their names, AirPod IDs, sleep times, time taken to play music, and song names.

- *Assigning to Dormitories*: Students are assigned to dormitories based on their sleep schedules. The program ensures a gap of at least 1 hour between students in the same dormitory to avoid disturbances during sleep.

- *Sleep Inducer*: The program simulates playing sleep-inducing music in all dormitories during the scheduled sleep times of students. It prints details of inmates in dormitories and plays the assigned music for the specified duration.

- *User Interaction*: Users can choose to view the details of inmates in dormitories or execute the sleep inducer through a simple menu interface.

- *Memory Management*: Dynamically allocated memory for inmate records is properly deallocated after use to prevent memory leaks.

*Files:*
- main.cpp: Contains the main implementation of the music dormitory management system.
- input.txt: Input file containing student records.
- README.md: This readme file describing the program and its functionalities
  
# Project Members 
Mohit Tigga - 202301111
Parv Rana - 202301112
Anshuman Bhagat - 202301170 
Bhumsar Boro - 202301002

# Division of Work 
- BHUMSAR BORO : Worked in assigning the dormatory to inmates and sleep inducer class 
- PARV RANA - Worked in making sleep inducer class and assigning dormatory to inmates
- MOHIT TIGGA - Worked in the main function of our code and documentary 
- ANSHUMAN BHAGAT - Worked in making initial blueprint classes  and documentary
  
# INPUT FILE FORMAT 
 Name ID timeinhours timeinminutes timetakentosleep songname
 EXAMPLE - JOHN 1 20 30 15 Lullaby 
