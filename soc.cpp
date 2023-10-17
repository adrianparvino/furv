#include <backends/cxxrtl/cxxrtl.h>

#if defined(CXXRTL_INCLUDE_CAPI_IMPL) || \
    defined(CXXRTL_INCLUDE_VCD_CAPI_IMPL)
#include <backends/cxxrtl/cxxrtl_capi.cc>
#endif

#if defined(CXXRTL_INCLUDE_VCD_CAPI_IMPL)
#include <backends/cxxrtl/cxxrtl_vcd_capi.cc>
#endif

using namespace cxxrtl_yosys;

namespace cxxrtl_design {

// \top: 1
// \src: top.v:2.1-108.10
struct p_top : public module {
	// \src: top.v:3.11-3.14
	/*input*/ value<1> p_clk;
	value<1> prev_p_clk;
	bool posedge_p_clk() const {
		return !prev_p_clk.slice<0>().val() && p_clk.slice<0>().val();
	}
	bool negedge_p_clk() const {
		return prev_p_clk.slice<0>().val() && !p_clk.slice<0>().val();
	}
	// \init: 0
	wire<6> p_data__out;
	// \hdlname: furv addr
	// \init: 0
	// \src: top.v:84.6-95.2|furv.v:7.23-7.27
	wire<32> p_furv_2e_addr;
	// \hdlname: furv mem
	// \init: 0
	// \src: top.v:84.6-95.2|furv.v:8.16-8.19
	wire<1> p_furv_2e_mem;
	// \hdlname: furv mem_write
	// \init: 0
	// \src: top.v:84.6-95.2|furv.v:9.16-9.25
	wire<1> p_furv_2e_mem__write;
	// \hdlname: furv pc
	// \init: 0
	// \src: top.v:84.6-95.2|furv.v:3.23-3.25
	wire<32> p_furv_2e_pc;
	// \src: top.v:8.11-8.14
	/*input*/ value<1> p_key;
	// \init: 63
	// \src: top.v:4.18-4.21
	/*output*/ wire<6> p_led;
	// \hdlname: ram ack
	// \init: 0
	// \src: top.v:65.5-77.2|ram.v:11.16-11.19
	wire<1> p_ram_2e_ack;
	// \src: top.v:6.11-6.18
	/*input*/ value<1> p_uart__rx;
	// \src: top.v:5.12-5.19
	/*output*/ value<1> p_uart__tx;
	// \hdlname: furv adjacent_pc
	// \src: top.v:84.6-95.2|furv.v:102.13-102.24
	/*outline*/ value<32> p_furv_2e_adjacent__pc;
	// \hdlname: furv alu arith_mode
	// \src: top.v:84.6-95.2|alu.v:9.9-9.19|furv.v:55.19-74.2
	/*outline*/ value<1> p_furv_2e_alu_2e_arith__mode;
	// \hdlname: furv alu arith_out
	// \src: top.v:84.6-95.2|alu.v:19.22-19.31|furv.v:55.19-74.2
	/*outline*/ value<32> p_furv_2e_alu_2e_arith__out;
	// \hdlname: furv alu au ra
	// \src: top.v:84.6-95.2|alu.v:28.21-35.2|au.v:4.21-4.23|furv.v:55.19-74.2
	/*outline*/ value<32> p_furv_2e_alu_2e_au_2e_ra;
	// \hdlname: furv alu au rb
	// \src: top.v:84.6-95.2|alu.v:28.21-35.2|au.v:5.21-5.23|furv.v:55.19-74.2
	/*outline*/ value<32> p_furv_2e_alu_2e_au_2e_rb;
	// \hdlname: furv alu comparison_out
	// \src: top.v:84.6-95.2|alu.v:21.10-21.24|furv.v:55.19-74.2
	/*outline*/ value<1> p_furv_2e_alu_2e_comparison__out;
	// \hdlname: furv alu cu eq_result
	// \src: top.v:84.6-95.2|alu.v:45.21-54.2|cu.v:18.6-18.15|furv.v:55.19-74.2
	/*outline*/ value<1> p_furv_2e_alu_2e_cu_2e_eq__result;
	// \hdlname: furv alu cu invert
	// \src: top.v:84.6-95.2|alu.v:45.21-54.2|cu.v:8.9-8.15|furv.v:55.19-74.2
	/*outline*/ value<1> p_furv_2e_alu_2e_cu_2e_invert;
	// \hdlname: furv alu cu lt
	// \src: top.v:84.6-95.2|alu.v:45.21-54.2|cu.v:7.9-7.11|furv.v:55.19-74.2
	/*outline*/ value<1> p_furv_2e_alu_2e_cu_2e_lt;
	// \hdlname: furv alu cu lt_result
	// \src: top.v:84.6-95.2|alu.v:45.21-54.2|cu.v:17.6-17.15|furv.v:55.19-74.2
	/*outline*/ value<1> p_furv_2e_alu_2e_cu_2e_lt__result;
	// \hdlname: furv alu cu ra
	// \src: top.v:84.6-95.2|alu.v:45.21-54.2|cu.v:4.21-4.23|furv.v:55.19-74.2
	/*outline*/ value<32> p_furv_2e_alu_2e_cu_2e_ra;
	// \hdlname: furv alu cu ra_
	// \src: top.v:84.6-95.2|alu.v:45.21-54.2|cu.v:14.18-14.21|furv.v:55.19-74.2
	/*outline*/ value<32> p_furv_2e_alu_2e_cu_2e_ra__;
	// \hdlname: furv alu cu rb
	// \src: top.v:84.6-95.2|alu.v:45.21-54.2|cu.v:5.21-5.23|furv.v:55.19-74.2
	/*outline*/ value<32> p_furv_2e_alu_2e_cu_2e_rb;
	// \hdlname: furv alu cu rb_
	// \src: top.v:84.6-95.2|alu.v:45.21-54.2|cu.v:15.18-15.21|furv.v:55.19-74.2
	/*outline*/ value<32> p_furv_2e_alu_2e_cu_2e_rb__;
	// \hdlname: furv alu cu unsigned_comparison
	// \src: top.v:84.6-95.2|alu.v:45.21-54.2|cu.v:9.9-9.28|furv.v:55.19-74.2
	/*outline*/ value<1> p_furv_2e_alu_2e_cu_2e_unsigned__comparison;
	// \hdlname: furv alu logic_alt
	// \src: top.v:84.6-95.2|alu.v:10.9-10.18|furv.v:55.19-74.2
	/*outline*/ value<1> p_furv_2e_alu_2e_logic__alt;
	// \hdlname: furv branch
	// \src: top.v:84.6-95.2|furv.v:46.6-46.12
	/*outline*/ value<1> p_furv_2e_branch;
	// \hdlname: furv branch_taken
	// \src: top.v:84.6-95.2|furv.v:101.6-101.18
	/*outline*/ value<1> p_furv_2e_branch__taken;
	// \hdlname: furv decoder compute
	// \src: top.v:84.6-95.2|decoder.v:27.6-27.13|furv.v:76.9-99.2
	/*outline*/ value<1> p_furv_2e_decoder_2e_compute;
	// \hdlname: furv decoder instruction
	// \src: top.v:84.6-95.2|decoder.v:2.16-2.27|furv.v:76.9-99.2
	// \unused_bits: 0 1
	/*outline*/ value<32> p_furv_2e_decoder_2e_instruction;
	// \hdlname: furv decoder lui
	// \src: top.v:84.6-95.2|decoder.v:29.6-29.9|furv.v:76.9-99.2
	/*outline*/ value<1> p_furv_2e_decoder_2e_lui;
	// \hdlname: furv decoder mem
	// \src: top.v:84.6-95.2|decoder.v:11.10-11.13|furv.v:76.9-99.2
	/*outline*/ value<1> p_furv_2e_decoder_2e_mem;
	// \hdlname: furv decoder r
	// \src: top.v:84.6-95.2|decoder.v:26.6-26.7|furv.v:76.9-99.2
	/*outline*/ value<1> p_furv_2e_decoder_2e_r;
	// \hdlname: furv decoder ra
	// \src: top.v:84.6-95.2|decoder.v:4.16-4.18|furv.v:76.9-99.2
	/*outline*/ value<5> p_furv_2e_decoder_2e_ra;
	// \hdlname: furv decoder sel_ra_pc
	// \src: top.v:84.6-95.2|decoder.v:8.10-8.19|furv.v:76.9-99.2
	/*outline*/ value<1> p_furv_2e_decoder_2e_sel__ra__pc;
	// \hdlname: furv imm
	// \src: top.v:84.6-95.2|furv.v:38.13-38.16
	/*outline*/ value<32> p_furv_2e_imm;
	// \hdlname: furv immdecoder b
	// \src: top.v:84.6-95.2|immdecoder.v:8.6-8.7|furv.v:50.12-53.2
	/*outline*/ value<1> p_furv_2e_immdecoder_2e_b;
	// \hdlname: furv immdecoder s
	// \src: top.v:84.6-95.2|immdecoder.v:7.6-7.7|furv.v:50.12-53.2
	/*outline*/ value<1> p_furv_2e_immdecoder_2e_s;
	// \hdlname: furv immdecoder u
	// \src: top.v:84.6-95.2|immdecoder.v:9.6-9.7|furv.v:50.12-53.2
	/*outline*/ value<1> p_furv_2e_immdecoder_2e_u;
	// \hdlname: furv read_ack
	// \src: top.v:84.6-95.2|furv.v:10.11-10.19
	/*outline*/ value<1> p_furv_2e_read__ack;
	// \src: top.v:33.6-33.16
	/*outline*/ value<1> p_led__select;
	// \hdlname: ram mem_en
	// \src: top.v:65.5-77.2|ram.v:8.11-8.17
	/*outline*/ value<1> p_ram_2e_mem__en;
	// \src: top.v:32.6-32.16
	/*outline*/ value<1> p_ram__select;
	// \hdlname: furv r
	// \src: top.v:84.6-95.2|furv.v:17.12-17.13
	memory<32> memory_p_furv_2e_r { 32u };
	// \hdlname: rom code
	// \src: top.v:79.5-82.2|rom.v:6.11-6.15
	memory<8> memory_p_rom_2e_code { 256u };

	p_top(interior) {}
	p_top() {
		reset();
	};

	void reset() override;
	bool eval() override;
	bool commit() override;

	void debug_eval();
	debug_outline debug_eval_outline { std::bind(&p_top::debug_eval, this) };

	void debug_info(debug_items &items, std::string path = "") override;
}; // struct p_top

void p_top::reset() {
	p_data__out = wire<6>{0u};
	p_furv_2e_addr = wire<32>{0u};
	p_furv_2e_mem = wire<1>{0u};
	p_furv_2e_mem__write = wire<1>{0u};
	p_furv_2e_pc = wire<32>{0u};
	p_led = wire<6>{0x3fu};
	p_ram_2e_ack = wire<1>{0u};
	// \src: top.v:79.5-82.2|rom.v:0.0-0.0
	static const value<8> mem_init_1[256] {
		value<8>{0x13u}, value<8>{0x01u}, value<8>{0xc0u}, value<8>{0x1fu},
		value<8>{0xefu}, value<8>{0x00u}, value<8>{0xc0u}, value<8>{0x03u},
		value<8>{0x6fu}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x13u}, value<8>{0x06u}, value<8>{0x05u}, value<8>{0x00u},
		value<8>{0x13u}, value<8>{0x05u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x93u}, value<8>{0xf6u}, value<8>{0x15u}, value<8>{0x00u},
		value<8>{0x63u}, value<8>{0x84u}, value<8>{0x06u}, value<8>{0x00u},
		value<8>{0x33u}, value<8>{0x05u}, value<8>{0xc5u}, value<8>{0x00u},
		value<8>{0x93u}, value<8>{0xd5u}, value<8>{0x15u}, value<8>{0x00u},
		value<8>{0x13u}, value<8>{0x16u}, value<8>{0x16u}, value<8>{0x00u},
		value<8>{0xe3u}, value<8>{0x96u}, value<8>{0x05u}, value<8>{0xfeu},
		value<8>{0x67u}, value<8>{0x80u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x93u}, value<8>{0x02u}, value<8>{0x00u}, value<8>{0x40u},
		value<8>{0x93u}, value<8>{0x82u}, value<8>{0xf2u}, value<8>{0xffu},
		value<8>{0xe3u}, value<8>{0x9eu}, value<8>{0x02u}, value<8>{0xfeu},
		value<8>{0x67u}, value<8>{0x80u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x13u}, value<8>{0x07u}, value<8>{0x40u}, value<8>{0x00u},
		value<8>{0x83u}, value<8>{0x26u}, value<8>{0x80u}, value<8>{0x40u},
		value<8>{0x93u}, value<8>{0x97u}, value<8>{0x26u}, value<8>{0x00u},
		value<8>{0xb3u}, value<8>{0x87u}, value<8>{0xd7u}, value<8>{0x00u},
		value<8>{0x23u}, value<8>{0x20u}, value<8>{0xf0u}, value<8>{0x40u},
		value<8>{0x13u}, value<8>{0x07u}, value<8>{0xf7u}, value<8>{0xffu},
		value<8>{0xe3u}, value<8>{0x16u}, value<8>{0x07u}, value<8>{0xfeu},
		value<8>{0x67u}, value<8>{0x80u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
		value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u}, value<8>{0x00u},
	};
	std::copy(std::begin(mem_init_1), std::end(mem_init_1), &memory_p_rom_2e_code.data[0]);
}

bool p_top::eval() {
	bool converged = true;
	bool posedge_p_clk = this->posedge_p_clk();
	bool negedge_p_clk = this->negedge_p_clk();
	// \src: top.v:84.6-95.2|immdecoder.v:19.11-19.16|furv.v:50.12-53.2
	value<32> i_auto_24_wreduce_2e_cc_3a_461_3a_run_24_3223;
	// \src: top.v:84.6-95.2|furv.v:107.7-107.81
	value<1> i_flatten_5c_furv_2e__24_logic__and_24_furv_2e_v_3a_107_24_161__Y;
	// \src: top.v:84.6-95.2|furv.v:137.11-137.49
	value<32> i_flatten_5c_furv_2e__24_ternary_24_furv_2e_v_3a_137_24_383__Y;
	// \src: top.v:84.6-95.2|alu.v:45.21-54.2|cu.v:14.25-14.45|furv.v:55.19-74.2
	value<1> i_flatten_5c_furv_2e__5c_alu_2e__5c_cu_2e__24_logic__not_24_cu_2e_v_3a_14_24_14__Y;
	// \src: top.v:84.6-95.2|immdecoder.v:24.19-24.24|furv.v:50.12-53.2
	value<1> i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_24_24_62__Y;
	// \src: top.v:84.6-95.2|immdecoder.v:24.12-24.17|furv.v:50.12-53.2
	value<1> i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_24_24_63__Y;
	// \src: top.v:84.6-95.2|immdecoder.v:36.12-36.21|furv.v:50.12-53.2
	value<1> i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_36_24_66__Y;
	// \src: top.v:84.6-95.2|immdecoder.v:43.15-43.24|furv.v:50.12-53.2
	value<1> i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_43_24_68__Y;
	// \hdlname: furv adjacent_pc
	// \src: top.v:84.6-95.2|furv.v:102.13-102.24
	value<32> p_furv_2e_adjacent__pc;
	// \hdlname: furv alu arith_out
	// \src: top.v:84.6-95.2|alu.v:19.22-19.31|furv.v:55.19-74.2
	value<32> p_furv_2e_alu_2e_arith__out;
	// \hdlname: furv alu au rb
	// \src: top.v:84.6-95.2|alu.v:28.21-35.2|au.v:5.21-5.23|furv.v:55.19-74.2
	value<32> p_furv_2e_alu_2e_au_2e_rb;
	// \hdlname: furv alu cu invert
	// \src: top.v:84.6-95.2|alu.v:45.21-54.2|cu.v:8.9-8.15|furv.v:55.19-74.2
	value<1> p_furv_2e_alu_2e_cu_2e_invert;
	// \hdlname: furv alu cu lt
	// \src: top.v:84.6-95.2|alu.v:45.21-54.2|cu.v:7.9-7.11|furv.v:55.19-74.2
	value<1> p_furv_2e_alu_2e_cu_2e_lt;
	// \hdlname: furv alu cu ra
	// \src: top.v:84.6-95.2|alu.v:45.21-54.2|cu.v:4.21-4.23|furv.v:55.19-74.2
	value<32> p_furv_2e_alu_2e_cu_2e_ra;
	// \hdlname: furv alu cu ra_
	// \src: top.v:84.6-95.2|alu.v:45.21-54.2|cu.v:14.18-14.21|furv.v:55.19-74.2
	value<32> p_furv_2e_alu_2e_cu_2e_ra__;
	// \hdlname: furv alu cu rb
	// \src: top.v:84.6-95.2|alu.v:45.21-54.2|cu.v:5.21-5.23|furv.v:55.19-74.2
	value<32> p_furv_2e_alu_2e_cu_2e_rb;
	// \hdlname: furv alu cu rb_
	// \src: top.v:84.6-95.2|alu.v:45.21-54.2|cu.v:15.18-15.21|furv.v:55.19-74.2
	value<32> p_furv_2e_alu_2e_cu_2e_rb__;
	// \hdlname: furv alu cu unsigned_comparison
	// \src: top.v:84.6-95.2|alu.v:45.21-54.2|cu.v:9.9-9.28|furv.v:55.19-74.2
	value<1> p_furv_2e_alu_2e_cu_2e_unsigned__comparison;
	// \hdlname: furv alu logic_alt
	// \src: top.v:84.6-95.2|alu.v:10.9-10.18|furv.v:55.19-74.2
	value<1> p_furv_2e_alu_2e_logic__alt;
	// \hdlname: furv branch_taken
	// \src: top.v:84.6-95.2|furv.v:101.6-101.18
	value<1> p_furv_2e_branch__taken;
	// \hdlname: furv decoder instruction
	// \src: top.v:84.6-95.2|decoder.v:2.16-2.27|furv.v:76.9-99.2
	// \unused_bits: 0 1
	value<32> p_furv_2e_decoder_2e_instruction;
	// \hdlname: furv decoder mem
	// \src: top.v:84.6-95.2|decoder.v:11.10-11.13|furv.v:76.9-99.2
	value<1> p_furv_2e_decoder_2e_mem;
	// \hdlname: furv decoder r
	// \src: top.v:84.6-95.2|decoder.v:26.6-26.7|furv.v:76.9-99.2
	value<1> p_furv_2e_decoder_2e_r;
	// \hdlname: furv imm
	// \src: top.v:84.6-95.2|furv.v:38.13-38.16
	value<32> p_furv_2e_imm;
	// \hdlname: furv immdecoder b
	// \src: top.v:84.6-95.2|immdecoder.v:8.6-8.7|furv.v:50.12-53.2
	value<1> p_furv_2e_immdecoder_2e_b;
	// \hdlname: furv immdecoder s
	// \src: top.v:84.6-95.2|immdecoder.v:7.6-7.7|furv.v:50.12-53.2
	value<1> p_furv_2e_immdecoder_2e_s;
	// \hdlname: furv immdecoder u
	// \src: top.v:84.6-95.2|immdecoder.v:9.6-9.7|furv.v:50.12-53.2
	value<1> p_furv_2e_immdecoder_2e_u;
	// \src: top.v:32.6-32.16
	value<1> p_ram__select;
	// \src: top.v:79.5-82.2|rom.v:11.3-11.7
	// memory \rom.code read port 3
	auto tmp_0 = memory_index(p_furv_2e_pc.curr.slice<7,2>().concat(value<2>{0x3u}).val(), 0, 256);
	CXXRTL_ASSERT(tmp_0.valid && "out of bounds read");
	if(tmp_0.valid) {
		p_furv_2e_decoder_2e_instruction.slice<31>().concat(p_furv_2e_alu_2e_logic__alt).concat(p_furv_2e_decoder_2e_instruction.slice<29,24>()) = memory_p_rom_2e_code[tmp_0.index];
	} else {
		p_furv_2e_decoder_2e_instruction.slice<31>().concat(p_furv_2e_alu_2e_logic__alt).concat(p_furv_2e_decoder_2e_instruction.slice<29,24>()) = value<8> {};
	}
	// \src: top.v:79.5-82.2|rom.v:13.3-13.7
	// memory \rom.code read port 1
	auto tmp_1 = memory_index(p_furv_2e_pc.curr.slice<7,2>().concat(value<2>{0x1u}).val(), 0, 256);
	CXXRTL_ASSERT(tmp_1.valid && "out of bounds read");
	if(tmp_1.valid) {
		p_furv_2e_decoder_2e_instruction.slice<15>().concat(p_furv_2e_alu_2e_cu_2e_lt).concat(p_furv_2e_alu_2e_cu_2e_unsigned__comparison).concat(p_furv_2e_alu_2e_cu_2e_invert).concat(p_furv_2e_decoder_2e_instruction.slice<11,8>()) = memory_p_rom_2e_code[tmp_1.index];
	} else {
		p_furv_2e_decoder_2e_instruction.slice<15>().concat(p_furv_2e_alu_2e_cu_2e_lt).concat(p_furv_2e_alu_2e_cu_2e_unsigned__comparison).concat(p_furv_2e_alu_2e_cu_2e_invert).concat(p_furv_2e_decoder_2e_instruction.slice<11,8>()) = value<8> {};
	}
	// \src: top.v:79.5-82.2|rom.v:12.3-12.7
	// memory \rom.code read port 2
	auto tmp_2 = memory_index(p_furv_2e_pc.curr.slice<7,2>().concat(value<2>{0x2u}).val(), 0, 256);
	CXXRTL_ASSERT(tmp_2.valid && "out of bounds read");
	if(tmp_2.valid) {
		p_furv_2e_decoder_2e_instruction.slice<23,16>() = memory_p_rom_2e_code[tmp_2.index];
	} else {
		p_furv_2e_decoder_2e_instruction.slice<23,16>() = value<8> {};
	}
	// \src: top.v:79.5-82.2|rom.v:14.3-14.7
	// memory \rom.code read port 0
	auto tmp_3 = memory_index(p_furv_2e_pc.curr.slice<7,2>().concat(value<2>{0u}).val(), 0, 256);
	CXXRTL_ASSERT(tmp_3.valid && "out of bounds read");
	if(tmp_3.valid) {
		p_furv_2e_decoder_2e_instruction.slice<7,0>() = memory_p_rom_2e_code[tmp_3.index];
	} else {
		p_furv_2e_decoder_2e_instruction.slice<7,0>() = value<8> {};
	}
	// connection
	p_furv_2e_decoder_2e_instruction.slice<30>().concat(p_furv_2e_decoder_2e_instruction.slice<14,12>()) = p_furv_2e_alu_2e_logic__alt.concat(p_furv_2e_alu_2e_cu_2e_lt).concat(p_furv_2e_alu_2e_cu_2e_unsigned__comparison).concat(p_furv_2e_alu_2e_cu_2e_invert).val();
	// \src: top.v:84.6-95.2|immdecoder.v:9.10-9.42|furv.v:50.12-53.2
	// cell $flatten\furv.\immdecoder.$logic_and$immdecoder.v:9$59
	p_furv_2e_immdecoder_2e_u = logic_and<1>(p_furv_2e_decoder_2e_instruction.slice<4>().val(), p_furv_2e_decoder_2e_instruction.slice<2>().val());
	// cells $flatten\furv.\immdecoder.$logic_and$immdecoder.v:8$58 $flatten\furv.\immdecoder.$eq$immdecoder.v:8$57
	p_furv_2e_immdecoder_2e_b = logic_and<1>(p_furv_2e_decoder_2e_instruction.slice<6>().val(), logic_not<1>(p_furv_2e_decoder_2e_instruction.slice<4,2>().val()));
	// \src: top.v:84.6-95.2|immdecoder.v:7.10-7.37|furv.v:50.12-53.2
	// cell $flatten\furv.\immdecoder.$eq$immdecoder.v:7$56
	p_furv_2e_immdecoder_2e_s = eq_uu<1>(p_furv_2e_decoder_2e_instruction.slice<6,3>().val(), value<3>{0x4u});
	// \src: top.v:84.6-95.2|immdecoder.v:24.12-24.17|furv.v:50.12-53.2
	// cell $flatten\furv.\immdecoder.$or$immdecoder.v:24$63
	i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_24_24_63__Y = or_uu<1>(p_furv_2e_immdecoder_2e_b, p_furv_2e_immdecoder_2e_u);
	// \src: top.v:84.6-95.2|furv.v:146.19-146.20
	// memory \furv.r read port 1
	auto tmp_4 = memory_index(p_furv_2e_decoder_2e_instruction.slice<24,20>().val(), 0, 32);
	CXXRTL_ASSERT(tmp_4.valid && "out of bounds read");
	if(tmp_4.valid) {
		p_furv_2e_alu_2e_cu_2e_rb = memory_p_furv_2e_r[tmp_4.index];
	} else {
		p_furv_2e_alu_2e_cu_2e_rb = value<32> {};
	}
	// \src: top.v:84.6-95.2|alu.v:45.21-54.2|cu.v:14.25-14.45|furv.v:55.19-74.2
	// cell $flatten\furv.\alu.\cu.$logic_not$cu.v:14$14
	i_flatten_5c_furv_2e__5c_alu_2e__5c_cu_2e__24_logic__not_24_cu_2e_v_3a_14_24_14__Y = logic_not<1>(p_furv_2e_alu_2e_cu_2e_unsigned__comparison);
	// \src: top.v:84.6-95.2|furv.v:56.24-56.25
	// memory \furv.r read port 0
	// cells $flatten\furv.\decoder.$ternary$decoder.v:31$39 $flatten\furv.\decoder.$eq$decoder.v:29$36
	auto tmp_5 = memory_index((eq_uu<1>(p_furv_2e_decoder_2e_instruction.slice<6,4>().concat(p_furv_2e_decoder_2e_instruction.slice<2>()).val(), value<3>{0x7u}) ? value<5>{0u} : p_furv_2e_decoder_2e_instruction.slice<19,15>().val()), 0, 32);
	CXXRTL_ASSERT(tmp_5.valid && "out of bounds read");
	if(tmp_5.valid) {
		p_furv_2e_alu_2e_cu_2e_ra = memory_p_furv_2e_r[tmp_5.index];
	} else {
		p_furv_2e_alu_2e_cu_2e_ra = value<32> {};
	}
	// \src: top.v:84.6-95.2|immdecoder.v:43.15-43.24|furv.v:50.12-53.2
	// cell $flatten\furv.\immdecoder.$or$immdecoder.v:43$68
	i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_43_24_68__Y = or_uu<1>(i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_24_24_63__Y, p_furv_2e_decoder_2e_instruction.slice<3>().val());
	// \src: top.v:84.6-95.2|alu.v:45.21-54.2|cu.v:15.25-15.59|furv.v:55.19-74.2
	// cell $flatten\furv.\alu.\cu.$xor$cu.v:15$17
	p_furv_2e_alu_2e_cu_2e_rb__.slice<31>() = xor_uu<1>(i_flatten_5c_furv_2e__5c_alu_2e__5c_cu_2e__24_logic__not_24_cu_2e_v_3a_14_24_14__Y, p_furv_2e_alu_2e_cu_2e_rb.slice<31>().val());
	// \src: top.v:84.6-95.2|alu.v:45.21-54.2|cu.v:14.25-14.59|furv.v:55.19-74.2
	// cell $flatten\furv.\alu.\cu.$xor$cu.v:14$15
	p_furv_2e_alu_2e_cu_2e_ra__.slice<31>() = xor_uu<1>(i_flatten_5c_furv_2e__5c_alu_2e__5c_cu_2e__24_logic__not_24_cu_2e_v_3a_14_24_14__Y, p_furv_2e_alu_2e_cu_2e_ra.slice<31>().val());
	// connection
	p_furv_2e_alu_2e_cu_2e_rb__.slice<30,0>() = p_furv_2e_alu_2e_cu_2e_rb.slice<30,0>().val();
	// connection
	p_furv_2e_alu_2e_cu_2e_ra__.slice<30,0>() = p_furv_2e_alu_2e_cu_2e_ra.slice<30,0>().val();
	// \src: top.v:84.6-95.2|immdecoder.v:24.19-24.24|furv.v:50.12-53.2
	// cell $flatten\furv.\immdecoder.$or$immdecoder.v:24$62
	i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_24_24_62__Y = or_uu<1>(p_furv_2e_immdecoder_2e_b, p_furv_2e_decoder_2e_instruction.slice<3>().val());
	// cells $flatten\furv.\immdecoder.$or$immdecoder.v:36$66 $flatten\furv.\immdecoder.$or$immdecoder.v:36$65
	i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_36_24_66__Y = or_uu<1>(or_uu<1>(p_furv_2e_immdecoder_2e_s, p_furv_2e_immdecoder_2e_b), p_furv_2e_immdecoder_2e_u);
	// \src: top.v:84.6-95.2|immdecoder.v:19.11-19.16|furv.v:50.12-53.2
	// cell $flatten\furv.\immdecoder.$or$immdecoder.v:19$61
	i_auto_24_wreduce_2e_cc_3a_461_3a_run_24_3223.slice<0>() = or_uu<1>(p_furv_2e_immdecoder_2e_u, p_furv_2e_decoder_2e_instruction.slice<3>().val());
	// connection
	i_auto_24_wreduce_2e_cc_3a_461_3a_run_24_3223.slice<31,1>() = value<31>{0u};
	// \src: top.v:84.6-95.2|decoder.v:38.14-38.54|furv.v:76.9-99.2
	// cell $flatten\furv.\decoder.$eq$decoder.v:38$50
	p_furv_2e_decoder_2e_mem = logic_not<1>(p_furv_2e_decoder_2e_instruction.slice<6>().concat(p_furv_2e_decoder_2e_instruction.slice<4>()).val());
	// cells $logic_and$top.v:32$494 $auto$opt_expr.cc:2126:replace_const_cells$3226 $auto$opt_expr.cc:2119:replace_const_cells$3227
	p_ram__select = logic_and<1>(reduce_or<1>(p_furv_2e_addr.curr.slice<31,8>().val()), logic_not<1>(p_furv_2e_addr.curr.slice<31,9>().val()));
	// \src: top.v:84.6-95.2|decoder.v:26.10-26.55|furv.v:76.9-99.2
	// cell $flatten\furv.\decoder.$eq$decoder.v:26$34
	p_furv_2e_decoder_2e_r = eq_uu<1>(p_furv_2e_decoder_2e_instruction.slice<6,4>().concat(p_furv_2e_decoder_2e_instruction.slice<2>()).val(), value<3>{0x6u});
	// \full_case: 1
	// \src: top.v:84.6-95.2|immdecoder.v:0.0-0.0|immdecoder.v:14.5-17.12|furv.v:50.12-53.2
	// cell $flatten\furv.\immdecoder.$procmux$3101
	p_furv_2e_imm.slice<30,20>() = (p_furv_2e_immdecoder_2e_u ? p_furv_2e_alu_2e_logic__alt.concat(p_furv_2e_decoder_2e_instruction.slice<29,20>()).val() : p_furv_2e_decoder_2e_instruction.slice<31>().val().repeat<11>().val());
	// \full_case: 1
	// \src: top.v:84.6-95.2|immdecoder.v:0.0-0.0|immdecoder.v:19.5-22.12|furv.v:50.12-53.2
	// cell $flatten\furv.\immdecoder.$procmux$3098
	p_furv_2e_imm.slice<19,12>() = (i_auto_24_wreduce_2e_cc_3a_461_3a_run_24_3223.slice<0>().val() ? p_furv_2e_decoder_2e_instruction.slice<19,15>().concat(p_furv_2e_alu_2e_cu_2e_lt).concat(p_furv_2e_alu_2e_cu_2e_unsigned__comparison).concat(p_furv_2e_alu_2e_cu_2e_invert).val() : p_furv_2e_decoder_2e_instruction.slice<31>().val().repeat<8>().val());
	// cells $flatten\furv.\immdecoder.$procmux$3092 $flatten\furv.\immdecoder.$procmux$3093_CMP0 $flatten\furv.\immdecoder.$procmux$3094_CMP0 $flatten\furv.\immdecoder.$procmux$3095_CMP0
	p_furv_2e_imm.slice<11>() = (eq_uu<1>(i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_24_24_63__Y.concat(i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_24_24_62__Y).val(), value<2>{0x3u}) ? p_furv_2e_decoder_2e_instruction.slice<7>().val() : (eq_uu<1>(i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_24_24_63__Y.concat(i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_24_24_62__Y).val(), value<2>{0x2u}) ? value<1>{0u} : (eq_uu<1>(i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_24_24_63__Y.concat(i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_24_24_62__Y).val(), value<1>{0x1u}) ? p_furv_2e_decoder_2e_instruction.slice<20>().val() : p_furv_2e_decoder_2e_instruction.slice<31>().val())));
	// \full_case: 1
	// \src: top.v:84.6-95.2|immdecoder.v:0.0-0.0|immdecoder.v:31.5-34.12|furv.v:50.12-53.2
	// cell $flatten\furv.\immdecoder.$procmux$3089
	p_furv_2e_imm.slice<10,5>() = (p_furv_2e_immdecoder_2e_u ? value<6>{0u} : p_furv_2e_alu_2e_logic__alt.concat(p_furv_2e_decoder_2e_instruction.slice<29,25>()).val());
	// cells $flatten\furv.\immdecoder.$procmux$3084 $flatten\furv.\immdecoder.$procmux$3085_CMP0 $flatten\furv.\immdecoder.$procmux$3086_CMP0
	p_furv_2e_imm.slice<4,1>() = (eq_uu<1>(i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_36_24_66__Y.concat(i_auto_24_wreduce_2e_cc_3a_461_3a_run_24_3223.slice<0>()).val(), value<2>{0x3u}) ? value<4>{0u} : (eq_uu<1>(i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_36_24_66__Y.concat(i_auto_24_wreduce_2e_cc_3a_461_3a_run_24_3223.slice<0>()).val(), value<2>{0x2u}) ? p_furv_2e_decoder_2e_instruction.slice<11,8>().val() : p_furv_2e_decoder_2e_instruction.slice<24,21>().val()));
	// cells $flatten\furv.\immdecoder.$procmux$3079 $flatten\furv.\immdecoder.$auto$opt_reduce.cc:128:opt_pmux$3208 $flatten\furv.\immdecoder.$procmux$3080_CMP0 $flatten\furv.\immdecoder.$procmux$3082_CMP0 $flatten\furv.\immdecoder.$procmux$3081_CMP0
	p_furv_2e_imm.slice<0>() = (reduce_or<1>(eq_uu<1>(p_furv_2e_immdecoder_2e_s.concat(i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_43_24_68__Y).val(), value<1>{0x1u}).concat(eq_uu<1>(p_furv_2e_immdecoder_2e_s.concat(i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_43_24_68__Y).val(), value<2>{0x3u})).val()) ? value<1>{0u} : (eq_uu<1>(p_furv_2e_immdecoder_2e_s.concat(i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_43_24_68__Y).val(), value<2>{0x2u}) ? p_furv_2e_decoder_2e_instruction.slice<7>().val() : p_furv_2e_decoder_2e_instruction.slice<20>().val()));
	// connection
	p_furv_2e_imm.slice<31>() = p_furv_2e_decoder_2e_instruction.slice<31>().val();
	// \src: top.v:84.6-95.2|furv.v:57.7-57.31
	// cell $flatten\furv.$ternary$furv.v:57$116
	p_furv_2e_alu_2e_au_2e_rb = (p_furv_2e_decoder_2e_r ? p_furv_2e_alu_2e_cu_2e_rb : p_furv_2e_decoder_2e_instruction.slice<31>().concat(p_furv_2e_imm.slice<30,0>()).val());
	// cells $flatten\furv.$logic_and$furv.v:107$161 $flatten\furv.$eq$furv.v:107$156 $flatten\furv.$logic_or$furv.v:107$160 $flatten\furv.$logic_not$furv.v:107$159 $flatten\furv.$logic_and$furv.v:107$158 $flatten\furv.$logic_not$furv.v:107$157 $ternary$top.v:22$491
	i_flatten_5c_furv_2e__24_logic__and_24_furv_2e_v_3a_107_24_161__Y = logic_and<1>(eq_uu<1>(p_furv_2e_decoder_2e_mem, p_furv_2e_mem.curr), logic_or<1>(logic_not<1>(logic_and<1>(p_furv_2e_decoder_2e_mem, logic_not<1>(p_furv_2e_decoder_2e_instruction.slice<5>().val()))), and_uu<1>(p_ram__select, p_ram_2e_ack.curr)));
	// cells $flatten\furv.\alu.\au.$sub$au.v:21$3 $flatten\furv.$ternary$furv.v:56$114 $flatten\furv.\decoder.$logic_or$decoder.v:35$48 $flatten\furv.\decoder.$logic_and$decoder.v:35$42 $flatten\furv.\decoder.$logic_and$decoder.v:35$40 $flatten\furv.\decoder.$eq$decoder.v:35$41 $flatten\furv.\decoder.$logic_and$decoder.v:35$47 $flatten\furv.\decoder.$logic_and$decoder.v:35$45 $flatten\furv.\decoder.$not$decoder.v:35$43 $flatten\furv.\decoder.$not$decoder.v:35$44 $flatten\furv.\decoder.$ne$decoder.v:35$46 $auto$opt_share.cc:244:merge_operators$3231 $auto$opt_share.cc:199:merge_operators$3228 $flatten\furv.\decoder.$logic_or$decoder.v:45$55 $flatten\furv.\decoder.$logic_and$decoder.v:45$53 $flatten\furv.\decoder.$logic_and$decoder.v:45$54 $flatten\furv.\decoder.$eq$decoder.v:27$35
	p_furv_2e_alu_2e_arith__out = sub_uu<32>((logic_or<1>(logic_and<1>(logic_and<1>(p_furv_2e_decoder_2e_instruction.slice<6>().val(), p_furv_2e_decoder_2e_instruction.slice<5>().val()), eq_uu<1>(p_furv_2e_decoder_2e_instruction.slice<3>().val(), p_furv_2e_decoder_2e_instruction.slice<2>().val())), logic_and<1>(logic_and<1>(not_u<1>(p_furv_2e_decoder_2e_instruction.slice<6>().val()), not_u<1>(p_furv_2e_decoder_2e_instruction.slice<5>().val())), ne_uu<1>(p_furv_2e_decoder_2e_instruction.slice<3>().val(), p_furv_2e_decoder_2e_instruction.slice<2>().val()))) ? p_furv_2e_pc.curr : p_furv_2e_alu_2e_cu_2e_ra), (logic_or<1>(logic_and<1>(p_furv_2e_decoder_2e_r, p_furv_2e_alu_2e_logic__alt), logic_and<1>(eq_uu<1>(p_furv_2e_decoder_2e_instruction.slice<6>().concat(p_furv_2e_decoder_2e_instruction.slice<4>()).concat(p_furv_2e_decoder_2e_instruction.slice<2>()).val(), value<2>{0x2u}), p_furv_2e_alu_2e_cu_2e_unsigned__comparison)) ? p_furv_2e_alu_2e_au_2e_rb : neg_u<32>(p_furv_2e_alu_2e_au_2e_rb)));
	// cells $flatten\furv.$logic_and$furv.v:101$120 $flatten\furv.\decoder.$eq$decoder.v:41$51 $flatten\furv.$logic_or$furv.v:101$119 $flatten\furv.\alu.\cu.$xor$cu.v:21$24 $flatten\furv.\alu.\cu.$ternary$cu.v:21$23 $flatten\furv.\alu.\cu.$logic_not$cu.v:18$21 $flatten\furv.\alu.\cu.$reduce_or$cu.v:18$20 $flatten\furv.\alu.\cu.$sub$cu.v:18$19 $flatten\furv.\alu.\cu.$lt$cu.v:17$18
	p_furv_2e_branch__taken = logic_and<1>(eq_uu<1>(p_furv_2e_decoder_2e_instruction.slice<6,4>().val(), value<3>{0x6u}), logic_or<1>(p_furv_2e_decoder_2e_instruction.slice<2>().val(), xor_uu<1>(p_furv_2e_alu_2e_cu_2e_invert, (p_furv_2e_alu_2e_cu_2e_lt ? lt_uu<1>(p_furv_2e_alu_2e_cu_2e_ra__.slice<31>().concat(p_furv_2e_alu_2e_cu_2e_ra.slice<30,0>()).val(), p_furv_2e_alu_2e_cu_2e_rb__.slice<31>().concat(p_furv_2e_alu_2e_cu_2e_rb.slice<30,0>()).val()) : logic_not<1>(reduce_or<1>(sub_uu<32>(p_furv_2e_alu_2e_cu_2e_ra__.slice<31>().concat(p_furv_2e_alu_2e_cu_2e_ra.slice<30,0>()).val(), p_furv_2e_alu_2e_cu_2e_rb__.slice<31>().concat(p_furv_2e_alu_2e_cu_2e_rb.slice<30,0>()).val())))))));
	// \src: top.v:84.6-95.2|furv.v:102.27-102.33
	// cell $flatten\furv.$add$furv.v:102$121
	p_furv_2e_adjacent__pc.slice<31,2>() = add_uu<30>(p_furv_2e_pc.curr.slice<31,2>().val(), value<1>{0x1u});
	// connection
	p_furv_2e_adjacent__pc.slice<1,0>() = p_furv_2e_pc.curr.slice<1,0>().val();
	// \src: top.v:84.6-95.2|furv.v:137.11-137.49
	// cell $flatten\furv.$ternary$furv.v:137$383
	i_flatten_5c_furv_2e__24_ternary_24_furv_2e_v_3a_137_24_383__Y = (p_furv_2e_branch__taken ? p_furv_2e_alu_2e_arith__out : p_furv_2e_adjacent__pc.slice<31,2>().concat(value<2>{0u}).val());
	// cells $flatten\ram.$procdff$3136 $logic_and$top.v:73$504
	if (posedge_p_clk) {
		p_ram_2e_ack.next = logic_and<1>(p_furv_2e_mem.curr, p_ram__select);
	}
	// \src: top.v:84.6-95.2|furv.v:104.1-149.4
	// cell $flatten\furv.$auto$ff.cc:266:slice$3220
	if (negedge_p_clk) {
		p_furv_2e_mem.next = p_furv_2e_decoder_2e_mem;
		if (i_flatten_5c_furv_2e__24_logic__and_24_furv_2e_v_3a_107_24_161__Y == value<1> {1u}) {
			p_furv_2e_mem.next = value<1>{0u};
		}
	}
	// \src: top.v:84.6-95.2|furv.v:104.1-149.4
	// cell $flatten\furv.$auto$ff.cc:266:slice$3219
	if (negedge_p_clk) {
		if (i_flatten_5c_furv_2e__24_logic__and_24_furv_2e_v_3a_107_24_161__Y == value<1> {0u}) {
			p_furv_2e_mem__write.next = p_furv_2e_decoder_2e_instruction.slice<5>().val();
		}
	}
	// cells $flatten\furv.$auto$ff.cc:266:slice$3213 $flatten\furv.$auto$opt_dff.cc:220:make_patterns_logic$3217 $flatten\furv.$logic_and$furv.v:111$231 $flatten\furv.$auto$opt_dff.cc:210:make_patterns_logic$3214
	if (negedge_p_clk) {
		if (reduce_and<1>(not_u<1>(i_flatten_5c_furv_2e__24_logic__and_24_furv_2e_v_3a_107_24_161__Y).concat(logic_and<1>(p_furv_2e_decoder_2e_mem, p_furv_2e_decoder_2e_instruction.slice<5>().val())).val()) == value<1> {1u}) {
			p_data__out.next = p_furv_2e_alu_2e_cu_2e_rb.slice<5,0>().val();
		}
	}
	// \src: top.v:84.6-95.2|furv.v:104.1-149.4
	// cell $flatten\furv.$auto$ff.cc:266:slice$3212
	if (negedge_p_clk) {
		if (i_flatten_5c_furv_2e__24_logic__and_24_furv_2e_v_3a_107_24_161__Y == value<1> {0u}) {
			p_furv_2e_addr.next = p_furv_2e_alu_2e_arith__out;
		}
	}
	// \src: top.v:84.6-95.2|furv.v:104.1-149.4
	// cell $auto$ff.cc:266:slice$3238
	if (negedge_p_clk) {
		if (i_flatten_5c_furv_2e__24_logic__and_24_furv_2e_v_3a_107_24_161__Y == value<1> {1u}) {
			p_furv_2e_pc.next.slice<31,2>() = i_flatten_5c_furv_2e__24_ternary_24_furv_2e_v_3a_137_24_383__Y.slice<31,2>().val();
		}
	}
	// cells $auto$ff.cc:266:slice$3233 $auto$opt_dff.cc:220:make_patterns_logic$3237
	if (negedge_p_clk) {
		if (reduce_and<1>(i_flatten_5c_furv_2e__24_logic__and_24_furv_2e_v_3a_107_24_161__Y.concat(p_furv_2e_branch__taken).val()) == value<1> {1u}) {
			p_furv_2e_pc.next.slice<1,0>() = i_flatten_5c_furv_2e__24_ternary_24_furv_2e_v_3a_137_24_383__Y.slice<1,0>().val();
		}
	}
	// cells $auto$ff.cc:266:slice$3222 $not$top.v:102$508 $logic_and$top.v:101$507 $logic_and$top.v:101$506 $eq$top.v:33$495
	if (posedge_p_clk) {
		if (logic_and<1>(logic_and<1>(p_furv_2e_mem.curr, p_furv_2e_mem__write.curr), eq_uu<1>(p_furv_2e_addr.curr, value<11>{0x400u})) == value<1> {1u}) {
			p_led.next = not_u<6>(p_data__out.curr);
		}
	}
	// connection
	p_uart__tx = value<1>{0x1u};
	return converged;
}

bool p_top::commit() {
	bool changed = false;
	prev_p_clk = p_clk;
	if (p_data__out.commit()) changed = true;
	if (p_furv_2e_addr.commit()) changed = true;
	if (p_furv_2e_mem.commit()) changed = true;
	if (p_furv_2e_mem__write.commit()) changed = true;
	if (p_furv_2e_pc.commit()) changed = true;
	if (p_led.commit()) changed = true;
	if (p_ram_2e_ack.commit()) changed = true;
	return changed;
}

void p_top::debug_eval() {
	// \src: top.v:84.6-95.2|immdecoder.v:19.11-19.16|furv.v:50.12-53.2
	value<32> i_auto_24_wreduce_2e_cc_3a_461_3a_run_24_3223;
	// \src: top.v:84.6-95.2|alu.v:45.21-54.2|cu.v:14.25-14.45|furv.v:55.19-74.2
	value<1> i_flatten_5c_furv_2e__5c_alu_2e__5c_cu_2e__24_logic__not_24_cu_2e_v_3a_14_24_14__Y;
	// \src: top.v:84.6-95.2|immdecoder.v:24.19-24.24|furv.v:50.12-53.2
	value<1> i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_24_24_62__Y;
	// \src: top.v:84.6-95.2|immdecoder.v:24.12-24.17|furv.v:50.12-53.2
	value<1> i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_24_24_63__Y;
	// \src: top.v:84.6-95.2|immdecoder.v:36.12-36.21|furv.v:50.12-53.2
	value<1> i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_36_24_66__Y;
	// \src: top.v:84.6-95.2|immdecoder.v:43.15-43.24|furv.v:50.12-53.2
	value<1> i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_43_24_68__Y;
	// \src: top.v:79.5-82.2|rom.v:11.3-11.7
	// memory \rom.code read port 3
	auto tmp_6 = memory_index(p_furv_2e_pc.curr.slice<7,2>().concat(value<2>{0x3u}).val(), 0, 256);
	CXXRTL_ASSERT(tmp_6.valid && "out of bounds read");
	if(tmp_6.valid) {
		p_furv_2e_decoder_2e_instruction.slice<31>().concat(p_furv_2e_alu_2e_logic__alt).concat(p_furv_2e_decoder_2e_instruction.slice<29,24>()) = memory_p_rom_2e_code[tmp_6.index];
	} else {
		p_furv_2e_decoder_2e_instruction.slice<31>().concat(p_furv_2e_alu_2e_logic__alt).concat(p_furv_2e_decoder_2e_instruction.slice<29,24>()) = value<8> {};
	}
	// \src: top.v:79.5-82.2|rom.v:13.3-13.7
	// memory \rom.code read port 1
	auto tmp_7 = memory_index(p_furv_2e_pc.curr.slice<7,2>().concat(value<2>{0x1u}).val(), 0, 256);
	CXXRTL_ASSERT(tmp_7.valid && "out of bounds read");
	if(tmp_7.valid) {
		p_furv_2e_decoder_2e_instruction.slice<15>().concat(p_furv_2e_alu_2e_cu_2e_lt).concat(p_furv_2e_alu_2e_cu_2e_unsigned__comparison).concat(p_furv_2e_alu_2e_cu_2e_invert).concat(p_furv_2e_decoder_2e_instruction.slice<11,8>()) = memory_p_rom_2e_code[tmp_7.index];
	} else {
		p_furv_2e_decoder_2e_instruction.slice<15>().concat(p_furv_2e_alu_2e_cu_2e_lt).concat(p_furv_2e_alu_2e_cu_2e_unsigned__comparison).concat(p_furv_2e_alu_2e_cu_2e_invert).concat(p_furv_2e_decoder_2e_instruction.slice<11,8>()) = value<8> {};
	}
	// \src: top.v:79.5-82.2|rom.v:12.3-12.7
	// memory \rom.code read port 2
	auto tmp_8 = memory_index(p_furv_2e_pc.curr.slice<7,2>().concat(value<2>{0x2u}).val(), 0, 256);
	CXXRTL_ASSERT(tmp_8.valid && "out of bounds read");
	if(tmp_8.valid) {
		p_furv_2e_decoder_2e_instruction.slice<23,16>() = memory_p_rom_2e_code[tmp_8.index];
	} else {
		p_furv_2e_decoder_2e_instruction.slice<23,16>() = value<8> {};
	}
	// \src: top.v:79.5-82.2|rom.v:14.3-14.7
	// memory \rom.code read port 0
	auto tmp_9 = memory_index(p_furv_2e_pc.curr.slice<7,2>().concat(value<2>{0u}).val(), 0, 256);
	CXXRTL_ASSERT(tmp_9.valid && "out of bounds read");
	if(tmp_9.valid) {
		p_furv_2e_decoder_2e_instruction.slice<7,0>() = memory_p_rom_2e_code[tmp_9.index];
	} else {
		p_furv_2e_decoder_2e_instruction.slice<7,0>() = value<8> {};
	}
	// connection
	p_furv_2e_decoder_2e_instruction.slice<30>().concat(p_furv_2e_decoder_2e_instruction.slice<14,12>()) = p_furv_2e_alu_2e_logic__alt.concat(p_furv_2e_alu_2e_cu_2e_lt).concat(p_furv_2e_alu_2e_cu_2e_unsigned__comparison).concat(p_furv_2e_alu_2e_cu_2e_invert).val();
	// \src: top.v:84.6-95.2|decoder.v:29.12-29.57|furv.v:76.9-99.2
	// cell $flatten\furv.\decoder.$eq$decoder.v:29$36
	p_furv_2e_decoder_2e_lui = eq_uu<1>(p_furv_2e_decoder_2e_instruction.slice<6,4>().concat(p_furv_2e_decoder_2e_instruction.slice<2>()).val(), value<3>{0x7u});
	// \src: top.v:84.6-95.2|immdecoder.v:9.10-9.42|furv.v:50.12-53.2
	// cell $flatten\furv.\immdecoder.$logic_and$immdecoder.v:9$59
	p_furv_2e_immdecoder_2e_u = logic_and<1>(p_furv_2e_decoder_2e_instruction.slice<4>().val(), p_furv_2e_decoder_2e_instruction.slice<2>().val());
	// cells $flatten\furv.\immdecoder.$logic_and$immdecoder.v:8$58 $flatten\furv.\immdecoder.$eq$immdecoder.v:8$57
	p_furv_2e_immdecoder_2e_b = logic_and<1>(p_furv_2e_decoder_2e_instruction.slice<6>().val(), logic_not<1>(p_furv_2e_decoder_2e_instruction.slice<4,2>().val()));
	// cells $flatten\furv.\decoder.$ternary$decoder.v:31$39 $flatten\furv.\decoder.$eq$decoder.v:29$36
	p_furv_2e_decoder_2e_ra = (p_furv_2e_decoder_2e_lui ? value<5>{0u} : p_furv_2e_decoder_2e_instruction.slice<19,15>().val());
	// \src: top.v:84.6-95.2|immdecoder.v:7.10-7.37|furv.v:50.12-53.2
	// cell $flatten\furv.\immdecoder.$eq$immdecoder.v:7$56
	p_furv_2e_immdecoder_2e_s = eq_uu<1>(p_furv_2e_decoder_2e_instruction.slice<6,3>().val(), value<3>{0x4u});
	// \src: top.v:84.6-95.2|immdecoder.v:24.12-24.17|furv.v:50.12-53.2
	// cell $flatten\furv.\immdecoder.$or$immdecoder.v:24$63
	i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_24_24_63__Y = or_uu<1>(p_furv_2e_immdecoder_2e_b, p_furv_2e_immdecoder_2e_u);
	// \src: top.v:84.6-95.2|furv.v:146.19-146.20
	// memory \furv.r read port 1
	auto tmp_10 = memory_index(p_furv_2e_decoder_2e_instruction.slice<24,20>().val(), 0, 32);
	CXXRTL_ASSERT(tmp_10.valid && "out of bounds read");
	if(tmp_10.valid) {
		p_furv_2e_alu_2e_cu_2e_rb = memory_p_furv_2e_r[tmp_10.index];
	} else {
		p_furv_2e_alu_2e_cu_2e_rb = value<32> {};
	}
	// \src: top.v:84.6-95.2|alu.v:45.21-54.2|cu.v:14.25-14.45|furv.v:55.19-74.2
	// cell $flatten\furv.\alu.\cu.$logic_not$cu.v:14$14
	i_flatten_5c_furv_2e__5c_alu_2e__5c_cu_2e__24_logic__not_24_cu_2e_v_3a_14_24_14__Y = logic_not<1>(p_furv_2e_alu_2e_cu_2e_unsigned__comparison);
	// \src: top.v:84.6-95.2|furv.v:56.24-56.25
	// memory \furv.r read port 0
	// cells $flatten\furv.\decoder.$ternary$decoder.v:31$39 $flatten\furv.\decoder.$eq$decoder.v:29$36
	auto tmp_11 = memory_index(p_furv_2e_decoder_2e_ra, 0, 32);
	CXXRTL_ASSERT(tmp_11.valid && "out of bounds read");
	if(tmp_11.valid) {
		p_furv_2e_alu_2e_cu_2e_ra = memory_p_furv_2e_r[tmp_11.index];
	} else {
		p_furv_2e_alu_2e_cu_2e_ra = value<32> {};
	}
	// \src: top.v:84.6-95.2|immdecoder.v:43.15-43.24|furv.v:50.12-53.2
	// cell $flatten\furv.\immdecoder.$or$immdecoder.v:43$68
	i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_43_24_68__Y = or_uu<1>(i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_24_24_63__Y, p_furv_2e_decoder_2e_instruction.slice<3>().val());
	// \src: top.v:84.6-95.2|alu.v:45.21-54.2|cu.v:15.25-15.59|furv.v:55.19-74.2
	// cell $flatten\furv.\alu.\cu.$xor$cu.v:15$17
	p_furv_2e_alu_2e_cu_2e_rb__.slice<31>() = xor_uu<1>(i_flatten_5c_furv_2e__5c_alu_2e__5c_cu_2e__24_logic__not_24_cu_2e_v_3a_14_24_14__Y, p_furv_2e_alu_2e_cu_2e_rb.slice<31>().val());
	// \src: top.v:84.6-95.2|alu.v:45.21-54.2|cu.v:14.25-14.59|furv.v:55.19-74.2
	// cell $flatten\furv.\alu.\cu.$xor$cu.v:14$15
	p_furv_2e_alu_2e_cu_2e_ra__.slice<31>() = xor_uu<1>(i_flatten_5c_furv_2e__5c_alu_2e__5c_cu_2e__24_logic__not_24_cu_2e_v_3a_14_24_14__Y, p_furv_2e_alu_2e_cu_2e_ra.slice<31>().val());
	// connection
	p_furv_2e_alu_2e_cu_2e_rb__.slice<30,0>() = p_furv_2e_alu_2e_cu_2e_rb.slice<30,0>().val();
	// connection
	p_furv_2e_alu_2e_cu_2e_ra__.slice<30,0>() = p_furv_2e_alu_2e_cu_2e_ra.slice<30,0>().val();
	// \src: top.v:84.6-95.2|immdecoder.v:24.19-24.24|furv.v:50.12-53.2
	// cell $flatten\furv.\immdecoder.$or$immdecoder.v:24$62
	i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_24_24_62__Y = or_uu<1>(p_furv_2e_immdecoder_2e_b, p_furv_2e_decoder_2e_instruction.slice<3>().val());
	// cells $flatten\furv.\immdecoder.$or$immdecoder.v:36$66 $flatten\furv.\immdecoder.$or$immdecoder.v:36$65
	i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_36_24_66__Y = or_uu<1>(or_uu<1>(p_furv_2e_immdecoder_2e_s, p_furv_2e_immdecoder_2e_b), p_furv_2e_immdecoder_2e_u);
	// \src: top.v:84.6-95.2|immdecoder.v:19.11-19.16|furv.v:50.12-53.2
	// cell $flatten\furv.\immdecoder.$or$immdecoder.v:19$61
	i_auto_24_wreduce_2e_cc_3a_461_3a_run_24_3223.slice<0>() = or_uu<1>(p_furv_2e_immdecoder_2e_u, p_furv_2e_decoder_2e_instruction.slice<3>().val());
	// connection
	i_auto_24_wreduce_2e_cc_3a_461_3a_run_24_3223.slice<31,1>() = value<31>{0u};
	// \src: top.v:84.6-95.2|decoder.v:38.14-38.54|furv.v:76.9-99.2
	// cell $flatten\furv.\decoder.$eq$decoder.v:38$50
	p_furv_2e_decoder_2e_mem = logic_not<1>(p_furv_2e_decoder_2e_instruction.slice<6>().concat(p_furv_2e_decoder_2e_instruction.slice<4>()).val());
	// cells $logic_and$top.v:32$494 $auto$opt_expr.cc:2126:replace_const_cells$3226 $auto$opt_expr.cc:2119:replace_const_cells$3227
	p_ram__select = logic_and<1>(reduce_or<1>(p_furv_2e_addr.curr.slice<31,8>().val()), logic_not<1>(p_furv_2e_addr.curr.slice<31,9>().val()));
	// \src: top.v:84.6-95.2|decoder.v:27.16-27.74|furv.v:76.9-99.2
	// cell $flatten\furv.\decoder.$eq$decoder.v:27$35
	p_furv_2e_decoder_2e_compute = eq_uu<1>(p_furv_2e_decoder_2e_instruction.slice<6>().concat(p_furv_2e_decoder_2e_instruction.slice<4>()).concat(p_furv_2e_decoder_2e_instruction.slice<2>()).val(), value<2>{0x2u});
	// \src: top.v:84.6-95.2|decoder.v:26.10-26.55|furv.v:76.9-99.2
	// cell $flatten\furv.\decoder.$eq$decoder.v:26$34
	p_furv_2e_decoder_2e_r = eq_uu<1>(p_furv_2e_decoder_2e_instruction.slice<6,4>().concat(p_furv_2e_decoder_2e_instruction.slice<2>()).val(), value<3>{0x6u});
	// \full_case: 1
	// \src: top.v:84.6-95.2|immdecoder.v:0.0-0.0|immdecoder.v:14.5-17.12|furv.v:50.12-53.2
	// cell $flatten\furv.\immdecoder.$procmux$3101
	p_furv_2e_imm.slice<30,20>() = (p_furv_2e_immdecoder_2e_u ? p_furv_2e_alu_2e_logic__alt.concat(p_furv_2e_decoder_2e_instruction.slice<29,20>()).val() : p_furv_2e_decoder_2e_instruction.slice<31>().val().repeat<11>().val());
	// \full_case: 1
	// \src: top.v:84.6-95.2|immdecoder.v:0.0-0.0|immdecoder.v:19.5-22.12|furv.v:50.12-53.2
	// cell $flatten\furv.\immdecoder.$procmux$3098
	p_furv_2e_imm.slice<19,12>() = (i_auto_24_wreduce_2e_cc_3a_461_3a_run_24_3223.slice<0>().val() ? p_furv_2e_decoder_2e_instruction.slice<19,15>().concat(p_furv_2e_alu_2e_cu_2e_lt).concat(p_furv_2e_alu_2e_cu_2e_unsigned__comparison).concat(p_furv_2e_alu_2e_cu_2e_invert).val() : p_furv_2e_decoder_2e_instruction.slice<31>().val().repeat<8>().val());
	// cells $flatten\furv.\immdecoder.$procmux$3092 $flatten\furv.\immdecoder.$procmux$3093_CMP0 $flatten\furv.\immdecoder.$procmux$3094_CMP0 $flatten\furv.\immdecoder.$procmux$3095_CMP0
	p_furv_2e_imm.slice<11>() = (eq_uu<1>(i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_24_24_63__Y.concat(i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_24_24_62__Y).val(), value<2>{0x3u}) ? p_furv_2e_decoder_2e_instruction.slice<7>().val() : (eq_uu<1>(i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_24_24_63__Y.concat(i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_24_24_62__Y).val(), value<2>{0x2u}) ? value<1>{0u} : (eq_uu<1>(i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_24_24_63__Y.concat(i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_24_24_62__Y).val(), value<1>{0x1u}) ? p_furv_2e_decoder_2e_instruction.slice<20>().val() : p_furv_2e_decoder_2e_instruction.slice<31>().val())));
	// \full_case: 1
	// \src: top.v:84.6-95.2|immdecoder.v:0.0-0.0|immdecoder.v:31.5-34.12|furv.v:50.12-53.2
	// cell $flatten\furv.\immdecoder.$procmux$3089
	p_furv_2e_imm.slice<10,5>() = (p_furv_2e_immdecoder_2e_u ? value<6>{0u} : p_furv_2e_alu_2e_logic__alt.concat(p_furv_2e_decoder_2e_instruction.slice<29,25>()).val());
	// cells $flatten\furv.\immdecoder.$procmux$3084 $flatten\furv.\immdecoder.$procmux$3085_CMP0 $flatten\furv.\immdecoder.$procmux$3086_CMP0
	p_furv_2e_imm.slice<4,1>() = (eq_uu<1>(i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_36_24_66__Y.concat(i_auto_24_wreduce_2e_cc_3a_461_3a_run_24_3223.slice<0>()).val(), value<2>{0x3u}) ? value<4>{0u} : (eq_uu<1>(i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_36_24_66__Y.concat(i_auto_24_wreduce_2e_cc_3a_461_3a_run_24_3223.slice<0>()).val(), value<2>{0x2u}) ? p_furv_2e_decoder_2e_instruction.slice<11,8>().val() : p_furv_2e_decoder_2e_instruction.slice<24,21>().val()));
	// cells $flatten\furv.\immdecoder.$procmux$3079 $flatten\furv.\immdecoder.$auto$opt_reduce.cc:128:opt_pmux$3208 $flatten\furv.\immdecoder.$procmux$3080_CMP0 $flatten\furv.\immdecoder.$procmux$3082_CMP0 $flatten\furv.\immdecoder.$procmux$3081_CMP0
	p_furv_2e_imm.slice<0>() = (reduce_or<1>(eq_uu<1>(p_furv_2e_immdecoder_2e_s.concat(i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_43_24_68__Y).val(), value<1>{0x1u}).concat(eq_uu<1>(p_furv_2e_immdecoder_2e_s.concat(i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_43_24_68__Y).val(), value<2>{0x3u})).val()) ? value<1>{0u} : (eq_uu<1>(p_furv_2e_immdecoder_2e_s.concat(i_flatten_5c_furv_2e__5c_immdecoder_2e__24_or_24_immdecoder_2e_v_3a_43_24_68__Y).val(), value<2>{0x2u}) ? p_furv_2e_decoder_2e_instruction.slice<7>().val() : p_furv_2e_decoder_2e_instruction.slice<20>().val()));
	// connection
	p_furv_2e_imm.slice<31>() = p_furv_2e_decoder_2e_instruction.slice<31>().val();
	// \src: top.v:84.6-95.2|alu.v:45.21-54.2|cu.v:17.18-17.27|furv.v:55.19-74.2
	// cell $flatten\furv.\alu.\cu.$lt$cu.v:17$18
	p_furv_2e_alu_2e_cu_2e_lt__result = lt_uu<1>(p_furv_2e_alu_2e_cu_2e_ra__.slice<31>().concat(p_furv_2e_alu_2e_cu_2e_ra.slice<30,0>()).val(), p_furv_2e_alu_2e_cu_2e_rb__.slice<31>().concat(p_furv_2e_alu_2e_cu_2e_rb.slice<30,0>()).val());
	// cells $flatten\furv.\alu.\cu.$logic_not$cu.v:18$21 $flatten\furv.\alu.\cu.$reduce_or$cu.v:18$20 $flatten\furv.\alu.\cu.$sub$cu.v:18$19
	p_furv_2e_alu_2e_cu_2e_eq__result = logic_not<1>(reduce_or<1>(sub_uu<32>(p_furv_2e_alu_2e_cu_2e_ra__.slice<31>().concat(p_furv_2e_alu_2e_cu_2e_ra.slice<30,0>()).val(), p_furv_2e_alu_2e_cu_2e_rb__.slice<31>().concat(p_furv_2e_alu_2e_cu_2e_rb.slice<30,0>()).val())));
	// \src: top.v:22.17-22.77
	// cell $ternary$top.v:22$491
	p_furv_2e_read__ack = and_uu<1>(p_ram__select, p_ram_2e_ack.curr);
	// \src: top.v:84.6-95.2|furv.v:57.7-57.31
	// cell $flatten\furv.$ternary$furv.v:57$116
	p_furv_2e_alu_2e_au_2e_rb = (p_furv_2e_decoder_2e_r ? p_furv_2e_alu_2e_cu_2e_rb : p_furv_2e_decoder_2e_instruction.slice<31>().concat(p_furv_2e_imm.slice<30,0>()).val());
	// cells $flatten\furv.\decoder.$logic_or$decoder.v:35$48 $flatten\furv.\decoder.$logic_and$decoder.v:35$42 $flatten\furv.\decoder.$logic_and$decoder.v:35$40 $flatten\furv.\decoder.$eq$decoder.v:35$41 $flatten\furv.\decoder.$logic_and$decoder.v:35$47 $flatten\furv.\decoder.$logic_and$decoder.v:35$45 $flatten\furv.\decoder.$not$decoder.v:35$43 $flatten\furv.\decoder.$not$decoder.v:35$44 $flatten\furv.\decoder.$ne$decoder.v:35$46
	p_furv_2e_decoder_2e_sel__ra__pc = logic_or<1>(logic_and<1>(logic_and<1>(p_furv_2e_decoder_2e_instruction.slice<6>().val(), p_furv_2e_decoder_2e_instruction.slice<5>().val()), eq_uu<1>(p_furv_2e_decoder_2e_instruction.slice<3>().val(), p_furv_2e_decoder_2e_instruction.slice<2>().val())), logic_and<1>(logic_and<1>(not_u<1>(p_furv_2e_decoder_2e_instruction.slice<6>().val()), not_u<1>(p_furv_2e_decoder_2e_instruction.slice<5>().val())), ne_uu<1>(p_furv_2e_decoder_2e_instruction.slice<3>().val(), p_furv_2e_decoder_2e_instruction.slice<2>().val())));
	// cells $flatten\furv.\decoder.$logic_or$decoder.v:45$55 $flatten\furv.\decoder.$logic_and$decoder.v:45$53 $flatten\furv.\decoder.$logic_and$decoder.v:45$54 $flatten\furv.\decoder.$eq$decoder.v:27$35
	p_furv_2e_alu_2e_arith__mode = logic_or<1>(logic_and<1>(p_furv_2e_decoder_2e_r, p_furv_2e_alu_2e_logic__alt), logic_and<1>(p_furv_2e_decoder_2e_compute, p_furv_2e_alu_2e_cu_2e_unsigned__comparison));
	// cells $flatten\furv.\alu.\cu.$xor$cu.v:21$24 $flatten\furv.\alu.\cu.$ternary$cu.v:21$23 $flatten\furv.\alu.\cu.$logic_not$cu.v:18$21 $flatten\furv.\alu.\cu.$reduce_or$cu.v:18$20 $flatten\furv.\alu.\cu.$sub$cu.v:18$19 $flatten\furv.\alu.\cu.$lt$cu.v:17$18
	p_furv_2e_alu_2e_comparison__out = xor_uu<1>(p_furv_2e_alu_2e_cu_2e_invert, (p_furv_2e_alu_2e_cu_2e_lt ? p_furv_2e_alu_2e_cu_2e_lt__result : p_furv_2e_alu_2e_cu_2e_eq__result));
	// cells $flatten\furv.$ternary$furv.v:56$114 $flatten\furv.\decoder.$logic_or$decoder.v:35$48 $flatten\furv.\decoder.$logic_and$decoder.v:35$42 $flatten\furv.\decoder.$logic_and$decoder.v:35$40 $flatten\furv.\decoder.$eq$decoder.v:35$41 $flatten\furv.\decoder.$logic_and$decoder.v:35$47 $flatten\furv.\decoder.$logic_and$decoder.v:35$45 $flatten\furv.\decoder.$not$decoder.v:35$43 $flatten\furv.\decoder.$not$decoder.v:35$44 $flatten\furv.\decoder.$ne$decoder.v:35$46
	p_furv_2e_alu_2e_au_2e_ra = (p_furv_2e_decoder_2e_sel__ra__pc ? p_furv_2e_pc.curr : p_furv_2e_alu_2e_cu_2e_ra);
	// \src: top.v:84.6-95.2|decoder.v:41.17-41.43|furv.v:76.9-99.2
	// cell $flatten\furv.\decoder.$eq$decoder.v:41$51
	p_furv_2e_branch = eq_uu<1>(p_furv_2e_decoder_2e_instruction.slice<6,4>().val(), value<3>{0x6u});
	// cells $flatten\furv.\alu.\au.$sub$au.v:21$3 $flatten\furv.$ternary$furv.v:56$114 $flatten\furv.\decoder.$logic_or$decoder.v:35$48 $flatten\furv.\decoder.$logic_and$decoder.v:35$42 $flatten\furv.\decoder.$logic_and$decoder.v:35$40 $flatten\furv.\decoder.$eq$decoder.v:35$41 $flatten\furv.\decoder.$logic_and$decoder.v:35$47 $flatten\furv.\decoder.$logic_and$decoder.v:35$45 $flatten\furv.\decoder.$not$decoder.v:35$43 $flatten\furv.\decoder.$not$decoder.v:35$44 $flatten\furv.\decoder.$ne$decoder.v:35$46 $auto$opt_share.cc:244:merge_operators$3231 $auto$opt_share.cc:199:merge_operators$3228 $flatten\furv.\decoder.$logic_or$decoder.v:45$55 $flatten\furv.\decoder.$logic_and$decoder.v:45$53 $flatten\furv.\decoder.$logic_and$decoder.v:45$54 $flatten\furv.\decoder.$eq$decoder.v:27$35
	p_furv_2e_alu_2e_arith__out = sub_uu<32>(p_furv_2e_alu_2e_au_2e_ra, (p_furv_2e_alu_2e_arith__mode ? p_furv_2e_alu_2e_au_2e_rb : neg_u<32>(p_furv_2e_alu_2e_au_2e_rb)));
	// cells $flatten\furv.$logic_and$furv.v:101$120 $flatten\furv.\decoder.$eq$decoder.v:41$51 $flatten\furv.$logic_or$furv.v:101$119 $flatten\furv.\alu.\cu.$xor$cu.v:21$24 $flatten\furv.\alu.\cu.$ternary$cu.v:21$23 $flatten\furv.\alu.\cu.$logic_not$cu.v:18$21 $flatten\furv.\alu.\cu.$reduce_or$cu.v:18$20 $flatten\furv.\alu.\cu.$sub$cu.v:18$19 $flatten\furv.\alu.\cu.$lt$cu.v:17$18
	p_furv_2e_branch__taken = logic_and<1>(p_furv_2e_branch, logic_or<1>(p_furv_2e_decoder_2e_instruction.slice<2>().val(), p_furv_2e_alu_2e_comparison__out));
	// \src: top.v:84.6-95.2|furv.v:102.27-102.33
	// cell $flatten\furv.$add$furv.v:102$121
	p_furv_2e_adjacent__pc.slice<31,2>() = add_uu<30>(p_furv_2e_pc.curr.slice<31,2>().val(), value<1>{0x1u});
	// connection
	p_furv_2e_adjacent__pc.slice<1,0>() = p_furv_2e_pc.curr.slice<1,0>().val();
	// \src: top.v:33.19-33.31
	// cell $eq$top.v:33$495
	p_led__select = eq_uu<1>(p_furv_2e_addr.curr, value<11>{0x400u});
	// \src: top.v:73.13-73.33
	// cell $logic_and$top.v:73$504
	p_ram_2e_mem__en = logic_and<1>(p_furv_2e_mem.curr, p_ram__select);
}

CXXRTL_EXTREMELY_COLD
void p_top::debug_info(debug_items &items, std::string path) {
	assert(path.empty() || path[path.size() - 1] == ' ');
	items.add(path + "clk", debug_item(p_clk, 0, debug_item::INPUT|debug_item::UNDRIVEN));
	items.add(path + "data_out", debug_item(p_data__out, 0, debug_item::DRIVEN_SYNC));
	items.add(path + "furv addr", debug_item(p_furv_2e_addr, 0, debug_item::DRIVEN_SYNC));
	items.add(path + "furv adjacent_pc", debug_item(debug_eval_outline, p_furv_2e_adjacent__pc, 0));
	items.add(path + "furv alu arith_mode", debug_item(debug_eval_outline, p_furv_2e_alu_2e_arith__mode, 0));
	items.add(path + "furv alu arith_out", debug_item(debug_eval_outline, p_furv_2e_alu_2e_arith__out, 0));
	items.add(path + "furv alu au ra", debug_item(debug_eval_outline, p_furv_2e_alu_2e_au_2e_ra, 0));
	items.add(path + "furv alu au rb", debug_item(debug_eval_outline, p_furv_2e_alu_2e_au_2e_rb, 0));
	items.add(path + "furv alu comparison_out", debug_item(debug_eval_outline, p_furv_2e_alu_2e_comparison__out, 0));
	items.add(path + "furv alu cu eq_result", debug_item(debug_eval_outline, p_furv_2e_alu_2e_cu_2e_eq__result, 0));
	items.add(path + "furv alu cu invert", debug_item(debug_eval_outline, p_furv_2e_alu_2e_cu_2e_invert, 0));
	items.add(path + "furv alu cu lt", debug_item(debug_eval_outline, p_furv_2e_alu_2e_cu_2e_lt, 0));
	items.add(path + "furv alu cu lt_result", debug_item(debug_eval_outline, p_furv_2e_alu_2e_cu_2e_lt__result, 0));
	items.add(path + "furv alu cu ra", debug_item(debug_eval_outline, p_furv_2e_alu_2e_cu_2e_ra, 0));
	items.add(path + "furv alu cu ra_", debug_item(debug_eval_outline, p_furv_2e_alu_2e_cu_2e_ra__, 0));
	items.add(path + "furv alu cu rb", debug_item(debug_eval_outline, p_furv_2e_alu_2e_cu_2e_rb, 0));
	items.add(path + "furv alu cu rb_", debug_item(debug_eval_outline, p_furv_2e_alu_2e_cu_2e_rb__, 0));
	items.add(path + "furv alu cu unsigned_comparison", debug_item(debug_eval_outline, p_furv_2e_alu_2e_cu_2e_unsigned__comparison, 0));
	items.add(path + "furv alu logic_alt", debug_item(debug_eval_outline, p_furv_2e_alu_2e_logic__alt, 0));
	items.add(path + "furv branch", debug_item(debug_eval_outline, p_furv_2e_branch, 0));
	items.add(path + "furv branch_taken", debug_item(debug_eval_outline, p_furv_2e_branch__taken, 0));
	items.add(path + "furv decoder compute", debug_item(debug_eval_outline, p_furv_2e_decoder_2e_compute, 0));
	items.add(path + "furv decoder instruction", debug_item(debug_eval_outline, p_furv_2e_decoder_2e_instruction, 0));
	items.add(path + "furv decoder lui", debug_item(debug_eval_outline, p_furv_2e_decoder_2e_lui, 0));
	items.add(path + "furv decoder mem", debug_item(debug_eval_outline, p_furv_2e_decoder_2e_mem, 0));
	items.add(path + "furv decoder r", debug_item(debug_eval_outline, p_furv_2e_decoder_2e_r, 0));
	items.add(path + "furv decoder ra", debug_item(debug_eval_outline, p_furv_2e_decoder_2e_ra, 0));
	items.add(path + "furv decoder sel_ra_pc", debug_item(debug_eval_outline, p_furv_2e_decoder_2e_sel__ra__pc, 0));
	items.add(path + "furv imm", debug_item(debug_eval_outline, p_furv_2e_imm, 0));
	items.add(path + "furv immdecoder b", debug_item(debug_eval_outline, p_furv_2e_immdecoder_2e_b, 0));
	items.add(path + "furv immdecoder s", debug_item(debug_eval_outline, p_furv_2e_immdecoder_2e_s, 0));
	items.add(path + "furv immdecoder u", debug_item(debug_eval_outline, p_furv_2e_immdecoder_2e_u, 0));
	items.add(path + "furv mem", debug_item(p_furv_2e_mem, 0, debug_item::DRIVEN_SYNC));
	items.add(path + "furv mem_write", debug_item(p_furv_2e_mem__write, 0, debug_item::DRIVEN_SYNC));
	items.add(path + "furv pc", debug_item(p_furv_2e_pc, 0, debug_item::DRIVEN_SYNC));
	items.add(path + "furv read_ack", debug_item(debug_eval_outline, p_furv_2e_read__ack, 0));
	items.add(path + "key", debug_item(p_key, 0, debug_item::INPUT|debug_item::UNDRIVEN));
	items.add(path + "led", debug_item(p_led, 0, debug_item::OUTPUT|debug_item::DRIVEN_SYNC));
	items.add(path + "led_select", debug_item(debug_eval_outline, p_led__select, 0));
	items.add(path + "ram ack", debug_item(p_ram_2e_ack, 0, debug_item::DRIVEN_SYNC));
	items.add(path + "ram mem_en", debug_item(debug_eval_outline, p_ram_2e_mem__en, 0));
	items.add(path + "ram_select", debug_item(debug_eval_outline, p_ram__select, 0));
	items.add(path + "uart_rx", debug_item(p_uart__rx, 0, debug_item::INPUT|debug_item::UNDRIVEN));
	static const value<1> const_p_uart__tx = value<1>{0x1u};
	items.add(path + "uart_tx", debug_item(const_p_uart__tx, 0));
	items.add(path + "furv r", debug_item(memory_p_furv_2e_r, 0));
	items.add(path + "rom code", debug_item(memory_p_rom_2e_code, 0));
}

} // namespace cxxrtl_design

extern "C"
cxxrtl_toplevel cxxrtl_design_create() {
	return new _cxxrtl_toplevel { std::unique_ptr<cxxrtl_design::p_top>(new cxxrtl_design::p_top) };
}
