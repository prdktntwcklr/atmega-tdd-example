 # ATmega168A programming

This project demonstrates the use of unit testing and test-driven development (TDD) when writing code for the ATmega168A microcontroller.

## Hardware Requirements
<ol dir="auto">
<li>Breadboard</li>
<li>Microcontroller (ATmega168A, 28-PDIP Package)</li>
<li>LED</li>
<li>Current-limiting resistor</li>
<li>Crystal oscillator</li>
<li>Programmer (I used the Pololu USB AVR Programmer v2.1)</li>
<li>Some wires</li>
</ol>

## Software Requirements
<ol dir="auto">
<li>AVR 8-bit GNU Toolchain</li>
<li>AVRDUDE</li>
<li>Ceedling Unit Testing Framework</li>
</ol>

## Unit Tests
<ol dir="auto">
<li>To run unit tests, execute the following command from within the home directory:</li>
<div class="snippet-clipboard-content notranslate position-relative overflow-auto" data-snippet-clipboard-copy-content="npm run start"><pre class="notranslate"><code>ceedling test:all</code></pre></div>
</ol>
