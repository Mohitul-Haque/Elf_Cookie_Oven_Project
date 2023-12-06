# Intro
This simple assignment will help give you a feel for what it is like to be a
embedded developer. We work on larger projects, have tools to help auto generate 
code.

# Suggested time limit
Aim to spend 4-6 hours. If you run out of time and aren't satisfied with your code,
you can leave `// TODO` comments where the code should be improved and how it should 
be improved. You can also leave comments regarding how the API or system components
could/should be modified/improved.

# Coding Conventions
Strongly prefer C99 over C89. Modern styles are good.

Even though this is a tiny toy example, write your code pretending it was a larger project.
We want to see how you would work on large real projects.

# Requirements
See `requirements.md` if you haven't already.

# Simulation Diagram
The diagram is not complete. You'll need to wire up the inputs and outputs.

* Use LEDs to show the status of outputs. You can add more LEDs if you like.
* Use a potentiometer to simulate the temperature sensor signal input.
* Use a potentiometer to simulate the temperature sensor `vref` input.
* Use a potentiometer or a 3 pin slide switch to simulate the door sensor input.

Feel free to modify as you see fit as long as you can demonstrate a working example.

## Wokwi Notes
* resistors don't really work in the wokwi simulator. Feel free to omit them for LEDs.
* a potentiometer in wokwi will automatically connect VCC and GND without you having to 
  wire them up. You can use a single wire from the potentiometer's SIG output.


# Assessment
## Code Correctness
For the types of projects we work on, correctness, safety and reliability are very important.

Does the code work properly? Can you demonstrate that it meets the requirements?

## Clean Code
Prefer easy to read and maintain code over extreme performance. Few people
want to maintain cryptic code that improves performance by 1%.
Premature optimization isn't a good thing.

**Note:** working ugly code that functions correctly is better than buggy pretty code.
It's OK to have ugly parts in your code as long as you put in a few comments about what
should be done differently given enough time.

## Optional Bonus Points
- Write at least one unit test for *your code*.
  - You can use the Arduino `setup()` function to run some tests and print the results.
  - We typically use gtest with Visual Studio or gcc/make for our unit testing but
  this can take a while to setup. Don't feel like you need to.
  - Unit testing code can be c++
- Improve api.h/cpp. If you do, please leave comments explaining your improvements 
(what was wrong before, why it is better now).


# Submission
When you `Save a copy` of this wokwi simulation, wokwi will automatically generate a new URL for you.
This new URL is how you share your simulation.

Saving your simulation is easier if you sign into wokwi.


# Tips
You can add additional files to wokwi to organize your code however you like. Click the dropdown
arrow beside "Library Manager".

Wokwi allows you to export and import files easily if you want to use a different IDE.

You can apply labels to the LEDs in wokwi. This is done by hand editing `diagram.json`.

Feel free to contact us with any questions. Pretend we are the client that you are designing
the oven for.

We are just starting to try out wokwi. It seems stable, but please contact us if you run
into issues.
