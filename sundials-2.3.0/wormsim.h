#ifndef APPLICATION_H
#define APPLICATION_H

// Steering neurons.
#define ASEL 0
#define ASER 1
#define AIYL 2
#define AIYR 3
#define AIZL 4
#define AIZR 5
#define SMBD 6
#define SMBV 7

// Steering synapses.
#define ASEL0 0
#define ASEL1 1
#define ASER0 2
#define ASER1 3
#define AIYL0 4
#define AIYR0 5
#define AIZL0 6
#define AIZL1 7
#define AIZR0 8
#define AIZR1 9

#include <emscripten/html5.h>
#include <emscripten/bind.h>

namespace e = emscripten;

class wormsim {

public:

	// Initialize.
	int init();

	// Set steering neuron synapse weight.
	void set_steering_synapse_weight(int synapse, double weight);

	// Step simulation with salt sensor stimulus.
	void step(double salt_stimulus);

	// Get neuron activations.
	double get_steering_activation(int neuron);
	double get_dorsal_motor_activation(int segment);
	double get_ventral_motor_activation(int segment);

	// Get muscle properties.
	double get_dorsal_muscle_activation(int segment);
	double get_ventral_muscle_activation(int segment);

	// Get body point.
	#define NSEG 48
	#define NBAR (NSEG+1)
	double get_body_point(int index);
	double get_segment_angle(int segment);

	// Terminate.
	void terminate();

	
};



EMSCRIPTEN_BINDINGS(wormsim) {
  e::class_<wormsim>("wormsim")
    .constructor()
      .function("init", &wormsim::init)
      .function("set_steering_synapse_weight", &wormsim::set_steering_synapse_weight)
      .function("step", &wormsim::step)
      .function("get_steering_activation", &wormsim::get_steering_activation)
      .function("get_dorsal_motor_activation", &wormsim::get_dorsal_motor_activation)
      .function("get_ventral_motor_activation", &wormsim::get_ventral_motor_activation)
      .function("get_body_point", &wormsim::get_body_point)
      .function("get_segment_angle", &wormsim::get_segment_angle)
      .function("terminate", &wormsim::terminate);

}


#endif