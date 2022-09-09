#include "llvm/IR/Function.h"
#include "llvm/IR/Module.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {

struct Template final : public ModulePass {
  static char ID;
  Template() : ModulePass(ID) {}

  bool runOnModule(Module &M) override {
    errs() << "Hello from the template pass\n";
    errs() << "Here are some function names: ";
    for (auto &F : M)
      errs().write_escaped(F.getName()) << " ";
    errs() << "\n\n";
    return false;
  }
};

}  // namespace

char Template::ID = 0;
static RegisterPass<Template> X("template", "Template Pass",
                             false /* Only looks at CFG */,
                             false /* Analysis Pass */);
