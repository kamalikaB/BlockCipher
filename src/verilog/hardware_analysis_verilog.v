`timescale 1ns/1ps

module tb_two_layer_encryption();

    // Inputs
    reg         clk;
    reg         rst;
    reg         start;
    reg [63:0]  in1;
    reg [63:0]  in2;

    // Outputs
    wire [63:0] encrypted_data;
    wire        done;

    // Instantiate the two_layer_encryption module
    two_layer_encryption uut (
        .clk(clk),
        .rst(rst),
        .start(start),
        .in1(in1),
        .in2(in2),
        .encrypted_data(encrypted_data),
        .done(done)
    );

    // Clock generation
    initial begin
        clk = 0;
        forever #2.5 clk = ~clk; // 100MHz clock
    end

    // Test vector generation
    initial begin
        // Initialize Inputs
        rst = 1;
        start = 0;
        in1 = 64'h0000000000000000;
        in2 = 64'h0000000000000000;

        // Apply reset
        #10;
        rst = 0;

        // Test Case 1
        in1 = 64'hA0B1C2DDEE889911;
        in2 = 64'hABCDEF1234567890;
        #10 start = 1;
        #10 start = 0;
        wait(done);
        $display("Test Case 1 Result: %h", encrypted_data);

        // Additional Test Cases can be added here

        // End of simulation
        #1000; // Increase time to allow the second layer to complete if needed
        $finish;
    end
endmodule



`timescale 1ns / 1ps

// XOR Module
module xor_module_64 (
    input  [63:0] in1,
    input  [63:0] in2,
    output [63:0] out
);
    assign out = in1 ^ in2;
endmodule

// 64 Bit Register
`timescale 1ns / 1ps
module reg64 (
    input clk,
    input rst, // reset signal
    input enable,
    input [63:0] data_in,
    output reg [63:0] data_out
);
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            data_out <= 64'b0;
        end else if (enable) begin
            data_out <= data_in;
        end
    end
endmodule

// MUX Module
`timescale 1ns / 1ps
module mux64 (
    input  [63:0] in0,
    input  [63:0] in1,
    input select,
    output [63:0] out
);
    assign out = select ? in0 : in1;
endmodule

// Counter Module
`timescale 1ns / 1ps
module counter_64 (
    input        clk,
    input        rst,
    input        enable,
    output reg [5:0] count,
    output reg      done
);
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            count <= 6'd0;
            done <= 1'b0;
        end else if (enable) begin
            if (count == 6'd63) begin
                count <= 6'd0;
                done <= 1'b1; // indicate completion
            end else begin
                count <= count + 1;
                done <= 1'b0;
            end
        end
    end
endmodule

// Evolution Logic for First Encryption Module
module evolution_first_layer (
    input  [63:0] in,
    output [63:0] out
);
    
 	    assign out[63] = 1'b1 & ~in[62];//error
    	assign out[62] = ((~in[63] & ((~in[62] & ~in[61]) | (in[62] & in[61]))) | (in[63] & ((~in[62] & in[61]) | (in[62] & ~in[61]))));//error
    	assign out[61] = ((~in[62] & ((~in[61] & ~in[60]) | (in[61] & in[60]))) | (in[62] & ((~in[61] & in[60]) | (in[61] & ~in[60]))));//error
    	assign out[60] = in[61] ^ in[59];//error
    	assign out[59] = in[60] ^ in[58];//error
    	assign out[58] = in[59] ^ in[57];//error
    
    	assign out[57] = ((~in[58] & ((~in[57] & ~in[56]) | (in[57] & in[56]))) | (in[58] & ((~in[57] & in[56]) | (in[57] & ~in[56]))));//error
    	assign out[56] = in[57] ^ in[55];//error
    	assign out[55] = in[56] ^ in[54];//error
    	assign out[54] = in[55] ^ in[53];//error
    
    	assign out[53] = ((~in[54] & ((~in[53] & ~in[52]) | (in[53] & in[52]))) | (in[54] & ((~in[53] & in[52]) | (in[53] & ~in[52]))));//error
    	assign out[52] = in[53] ^ in[51];//error
    	assign out[51] = in[52] ^ in[50];//error
    	assign out[50] = in[51] ^ in[49];//error
    
    	assign out[49] = ((~in[50] & ((~in[49] & ~in[48]) | (in[49] & in[48]))) | (in[50] & ((~in[49] & in[48]) | (in[49] & ~in[48]))));//error
    	assign out[48] = in[49] ^ in[47];//error
    	assign out[47] = in[48] ^ in[46];//error
    	assign out[46] = in[47] ^ in[45];//error
    
    	assign out[45] = ((~in[46] & ((~in[45] & ~in[44]) | (in[45] & in[44]))) | (in[46] & ((~in[45] & in[44]) | (in[45] & ~in[44]))));//error
    	assign out[44] = in[45] ^ in[43];//error
    	assign out[43] = in[44] ^ in[42];//error
    	assign out[42] = in[43] ^ in[41];//error
    
    	assign out[41] = ((~in[42] & ((~in[41] & ~in[40]) | (in[41] & in[40]))) | (in[42] & ((~in[41] & in[40]) | (in[41] & ~in[40]))));//error
    	assign out[40] = in[41] ^ in[39];//error
    	assign out[39] = in[40] ^ in[38];//error
    	assign out[38] = in[39] ^ in[37];//error
    
    	assign out[37] = ((~in[38] & ((~in[37] & ~in[36]) | (in[37] & in[36]))) | (in[38] & ((~in[37] & in[36]) | (in[37] & ~in[36]))));//error
    	assign out[36] = in[37] ^ in[35];//error
    	assign out[35] = in[36] ^ in[34];//error
    	assign out[34] = in[35] ^ in[33];//error
    
    	assign out[33] = ((~in[34] & ((~in[33] & ~in[32]) | (in[33] & in[32]))) | (in[34] & ((~in[33] & in[32]) | (in[33] & ~in[32]))));//error
    	assign out[32] = in[33] ^ in[31];//error
    	assign out[31] = in[32] ^ in[30];//error
    	assign out[30] = in[31] ^ in[29];//error
    
    	assign out[29] = ((~in[30] & ((~in[29] & ~in[28]) | (in[29] & in[28]))) | (in[30] & ((~in[29] & in[28]) | (in[29] & ~in[28]))));//error
    	assign out[28] = in[29] ^ in[27];//error
    	assign out[27] = in[28] ^ in[26];//error
    	assign out[26] = in[27] ^ in[25];//error
    
    	assign out[25] = ((~in[26] & ((~in[25] & ~in[24]) | (in[25] & in[24]))) | (in[26] & ((~in[25] & in[24]) | (in[25] & ~in[24]))));//error
    	assign out[24] = in[25] ^ in[23];//error
    	assign out[23] = in[24] ^ in[22];//error
    	assign out[22] = in[23] ^ in[21];//error
    
    	assign out[21] = ((~in[22] & ((~in[21] & ~in[20]) | (in[21] & in[20]))) | (in[22] & ((~in[21] & in[20]) | (in[21] & ~in[20]))));//error
    	assign out[20] = in[21] ^ in[19];//error
    	assign out[19] = in[20] ^ in[18];//error
    	assign out[18] = in[19] ^ in[17];//error
    
    	assign out[17] = ((~in[18] & ((~in[17] & ~in[16]) | (in[17] & in[16]))) | (in[18] & ((~in[17] & in[16]) | (in[17] & ~in[16]))));//error
    	assign out[16] = in[17] ^ in[15];//error
    	assign out[15] = in[16] ^ in[14];//error
    	assign out[14] = in[15] ^ in[13];//error
    
    	assign out[13] = ((~in[14] & ((~in[13] & ~in[12]) | (in[13] & in[12]))) | (in[14] & ((~in[13] & in[12]) | (in[13] & ~in[12]))));//error
    	assign out[12] = in[13] ^ in[11];//error
    	assign out[11] = in[12] ^ in[10];//error
    	assign out[10] = in[11] ^ in[9];//error
    
    	assign out[9] = ((~in[10] & ((~in[9] & ~in[8]) | (in[9] & in[8]))) | (in[10] & ((~in[9] & in[8]) | (in[9] & ~in[8]))));//error
    	assign out[8] = in[9] ^ in[7];//error
    	assign out[7] = in[8] ^ in[6];//error
    	assign out[6] = in[7] ^ in[5];//error
    
    	assign out[5] = ((~in[6] & ((~in[5] & ~in[4]) | (in[5] & in[4]))) | (in[6] & ((~in[5] & in[4]) | (in[5] & ~in[4]))));//error
    	assign out[4] = in[5] ^ in[3];//error
    	assign out[3] = in[4] ^ in[2];//error
    	assign out[2] = in[3] ^ in[1];//error
    
    	assign out[1] = ((~in[0] & (~in[1] | ~in[2])) | (in[2] & in[1] & in[0]));
    	assign out[0] = 1'b1 & in[1];
        
   
endmodule

// Evolution Logic for Second Encryption Module
module evolution_second_layer (
    input  [63:0] in,
    output [63:0] out
);
	assign out[63] = (~in[63] & ~in[62]) | (in[63] & in[62]);
	assign out[62] = (~in[62] & ~in[61]) | (in[62] & in[61]);
	assign out[61] = (~in[61] & ~in[60]) | (in[61] & in[60]);
	assign out[60] = (~in[60] & ~in[59]) | (in[60] & in[59]);
	assign out[59] = (~in[59] & ~in[58]) | (in[59] & in[58]);
	assign out[58] = (~in[58] & ~in[57]) | (in[58] & in[57]);
	assign out[57] = (~in[57] & ~in[56]) | (in[57] & in[56]);
	assign out[56] = (~in[56] & ~in[55]) | (in[56] & in[55]);
	assign out[55] = (~in[55] & ~in[54]) | (in[55] & in[54]);
	assign out[54] = (~in[54] & ~in[53]) | (in[54] & in[53]);
	assign out[53] = (~in[53] & ~in[52]) | (in[53] & in[52]);
	assign out[52] = (~in[52] & ~in[51]) | (in[52] & in[51]);
	assign out[51] = (~in[51] & ~in[50]) | (in[51] & in[50]);
	assign out[50] = (~in[50] & ~in[49]) | (in[50] & in[49]);
	assign out[49] = (~in[49] & ~in[48]) | (in[49] & in[48]);
	assign out[48] = (~in[48] & ~in[47]) | (in[48] & in[47]);
	assign out[47] = (~in[47] & ~in[46]) | (in[47] & in[46]);
	assign out[46] = (~in[46] & ~in[45]) | (in[46] & in[45]);
	assign out[45] = (~in[45] & ~in[44]) | (in[45] & in[44]);
	assign out[44] = (~in[44] & ~in[43]) | (in[44] & in[43]);
	assign out[43] = (~in[43] & ~in[42]) | (in[43] & in[42]);
	assign out[42] = (~in[42] & ~in[41]) | (in[42] & in[41]);
	assign out[41] = (~in[41] & ~in[40]) | (in[41] & in[40]);
	assign out[40] = (~in[40] & ~in[39]) | (in[40] & in[39]);
	assign out[39] = (~in[39] & ~in[38]) | (in[39] & in[38]);
	assign out[38] = (~in[38] & ~in[37]) | (in[38] & in[37]);
	assign out[37] = (~in[37] & ~in[36]) | (in[37] & in[36]);
	assign out[36] = (~in[36] & ~in[35]) | (in[36] & in[35]);
	assign out[35] = (~in[35] & ~in[34]) | (in[35] & in[34]);
	assign out[34] = (~in[34] & ~in[33]) | (in[34] & in[33]);
	assign out[33] = (~in[33] & ~in[32]) | (in[33] & in[32]);
	assign out[32] = (~in[32] & ~in[31]) | (in[32] & in[31]);
	assign out[31] = (~in[31] & ~in[30]) | (in[31] & in[30]);
	assign out[30] = (~in[30] & ~in[29]) | (in[30] & in[29]);
	assign out[29] = (~in[29] & ~in[28]) | (in[29] & in[28]);
	assign out[28] = (~in[28] & ~in[27]) | (in[28] & in[27]);
	assign out[27] = (~in[27] & ~in[26]) | (in[27] & in[26]);
	assign out[26] = (~in[26] & ~in[25]) | (in[26] & in[25]);
	assign out[25] = (~in[25] & ~in[24]) | (in[25] & in[24]);
	assign out[24] = (~in[24] & ~in[23]) | (in[24] & in[23]);
	assign out[23] = (~in[23] & ~in[22]) | (in[23] & in[22]);
	assign out[22] = (~in[22] & ~in[21]) | (in[22] & in[21]);	
	assign out[21] = (~in[21] & ~in[20]) | (in[21] & in[20]);
	assign out[20] = (~in[20] & ~in[19]) | (in[20] & in[19]);
	assign out[19] = (~in[19] & ~in[18]) | (in[19] & in[18]);
	assign out[18] = (~in[18] & ~in[17]) | (in[18] & in[17]);
	assign out[17] = (~in[17] & ~in[16]) | (in[17] & in[16]);
	assign out[16] = (~in[16] & ~in[15]) | (in[16] & in[15]);
	assign out[15] = (~in[15] & ~in[14]) | (in[15] & in[14]);
	assign out[14] = (~in[14] & ~in[13]) | (in[14] & in[13]);
	assign out[13] = (~in[13] & ~in[12]) | (in[13] & in[12]);
	assign out[12] = (~in[12] & ~in[11]) | (in[12] & in[11]);
	assign out[11] = (~in[11] & ~in[10]) | (in[11] & in[10]);
	assign out[10] = (~in[10] & ~in[9]) | (in[10] & in[9]);
	assign out[9] = (~in[9] & ~in[8]) | (in[9] & in[8]);
	assign out[8] = (~in[8] & ~in[7]) | (in[8] & in[7]);
	assign out[7] = (~in[7] & ~in[6]) | (in[7] & in[6]);
	assign out[6] = (~in[6] & ~in[5]) | (in[6] & in[5]);
	assign out[5] = (~in[5] & ~in[4]) | (in[5] & in[4]);
	assign out[4] = (~in[4] & ~in[3]) | (in[4] & in[3]);
	assign out[3] = (~in[3] & ~in[2]) | (in[3] & in[2]);
	assign out[2] = (~in[2] & ~in[1]) | (in[2] & in[1]);
	assign out[1] = (~in[1] & ~in[0]) | (in[1] & in[0]);


	assign out[0] = (~in[0] & 1'b1) | (in[0] & 1'b0);
	

endmodule

// First Encryption Layer
`timescale 1ns / 1ps

// Updated First Encryption Layer
module encryption_first_layer (
    input        clk,
    input        rst,
    input        start,
    input [63:0] data_in,
    output [63:0] data_out,
    output       done
);
    wire [63:0] current_state;
    wire [63:0] next_state;
    reg [5:0]  count;
    reg        enable;
    reg        done_reg;

    assign done = done_reg;

    // Enable logic
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            enable <= 1'b0;
            count  <= 6'd0;
            done_reg <= 1'b0;
        end else if (start) begin
            enable <= 1'b1;
            done_reg <= 1'b0;
        end else if (enable) begin
            if (count == 6'd63) begin
                enable <= 1'b0;
                done_reg <= 1'b1;
            end else begin
                count <= count + 1;
            end
        end
    end
    
    always @(posedge clk) begin
        // Print debugging information for each clock cycle
        if (rst || enable || start) begin
            $display("Time: %0t | Enable: %b, Start: %b, Count: %d", $time, enable, start, count);
        end
    end

    // Evolution Logic
    evolution_first_layer evo_first_inst (
        .in(current_state),
        .out(next_state)
    );

    // MUX to load initial data or next state
    mux64 mux_inst (
        .in0(data_in),
        .in1(next_state),
        .select(count == 6'd0),
        .out(data_out)
    );

    // Register to hold current state
    reg64 reg_inst (
        .clk(clk),
        .rst(rst),
        .enable(enable),
        .data_in(data_out),
        .data_out(current_state)
    );
endmodule
// Second Encryption Layer
// Updated Second Encryption Layer
module encryption_second_layer (
    input        clk,
    input        rst,
    input        start,
    input [63:0] data_in,
    output [63:0] data_out,
    output       done
);
    wire [63:0] current_state;
    wire [63:0] next_state;
    reg [5:0]   count;
    reg         enable;
    reg         done_reg;
    reg         start_d;      // Delayed start signal for synchronization
    reg         start_processed; // Flag to ensure start is processed once

    assign done = done_reg;

    // Synchronize start signal with clock
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            start_d <= 1'b0;
        end else begin
            start_d <= start;
        end
    end

    // Handle enable and count logic
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            enable <= 1'b0;
            count  <= 6'd0;
            done_reg <= 1'b0;
            start_processed <= 1'b0;
        end else if (start && !start_processed) begin
            enable <= 1'b1;
            done_reg <= 1'b0;
            count <= 6'd0;  // Reset count when start is asserted
            start_processed <= 1'b1; // Indicate start has been processed
        end else if (enable) begin
            if (count == 6'd63) begin
                enable <= 1'b0;
                done_reg <= 1'b1;
                start_processed <= 1'b0; // Reset start_processed when done
            end else begin
                count <= count + 1;
            end
        end
    end

    // Debugging information
    always @(posedge clk) begin
        if (rst || enable || start_d) begin
            $display("Time: %0t | Enable: %b, Start: %b, Count: %d", $time, enable, start_d, count);
        end
    end

    // Evolution Logic
    evolution_second_layer evo_second_inst (
        .in(current_state),
        .out(next_state)
    );

    // MUX to load initial data or next state
    mux64 mux_inst (
        .in0(data_in),
        .in1(next_state),
        .select(count == 6'd0),
        .out(data_out)
    );

    // Register to hold current state
    reg64 reg_inst (
        .clk(clk),
        .rst(rst),
        .enable(enable),
        .data_in(data_out),
        .data_out(current_state)
    );
endmodule

// Two-Layer Encryption Top Module
module two_layer_encryption (
    input        clk,
    input        rst,
    input        start,
    input [63:0] in1,
    input [63:0] in2,
    output [63:0] encrypted_data,
    output       done
);
    wire [63:0] xor_result;
    wire [63:0] first_layer_output;
    wire        first_layer_done;
    wire        second_layer_done;

    // XOR Operation
    xor_module_64 xor_inst (
        .in1(in1),
        .in2(in2),
        .out(xor_result)
    );

    // First Encryption Layer
    encryption_first_layer first_layer_inst (
        .clk(clk),
        .rst(rst),
        .start(start),
        .data_in(xor_result),
        .data_out(first_layer_output),
        .done(first_layer_done)
    );

    // Second Encryption Layer
    encryption_second_layer second_layer_inst (
        .clk(clk),
        .rst(rst),
        .start(first_layer_done),
        .data_in(first_layer_output),
        .data_out(encrypted_data),
        .done(second_layer_done)
    );

    assign done = second_layer_done;
endmodule