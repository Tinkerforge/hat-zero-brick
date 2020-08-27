#include "bindings/hal_common.h"
#include "bindings/brick_hat_zero.h"

#define UID "XXYYZZ" // Change XXYYZZ to the UID of your HAT Zero Brick

void check(int rc, const char* msg);

void example_setup(TF_HalContext *hal);
void example_loop(TF_HalContext *hal);


static TF_HATZero hz;

void example_setup(TF_HalContext *hal) {
	// Create device object
	check(tf_hat_zero_create(&hz, UID, hal), "create device object");

	// Get current voltage
	uint16_t voltage;
	check(tf_hat_zero_get_usb_voltage(&hz, &voltage), "get voltage");

	tf_hal_printf("Voltage: %d 1/%d V\n", voltage, 1000.0);
}

void example_loop(TF_HalContext *hal) {
	// Poll for callbacks
	tf_hal_callback_tick(hal, 0);
}
