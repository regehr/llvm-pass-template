#include "llvm/IR/Function.h"
#include "llvm/IR/Module.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"

namespace {

  struct Template final : public llvm::ModulePass {
  static char ID;
  Template() : ModulePass(ID) {}

    bool runOnModule(llvm::Module &M) override {
      llvm::errs() << "Hello from the template pass!\n";
      llvm::errs() << "Here are the functions in your module: ";
      for (auto &F : M)
	llvm::errs().write_escaped(F.getName()) << " ";
      llvm::errs() << "\n\n";
      return false;
    }
  };

} // namespace

char Template::ID = 0;
llvm::RegisterPass<Template> X("template", "Template Pass", false, false);
